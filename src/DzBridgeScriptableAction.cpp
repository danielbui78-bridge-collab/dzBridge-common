#include <QtGui/qcheckbox.h>
#include <QtGui/QMessageBox>
#include <QtNetwork/qudpsocket.h>
#include <QtNetwork/qabstractsocket.h>
#include <QUuid.h>

#include <dzapp.h>
#include <dzscene.h>
#include <dzmainwindow.h>
#include <dzshape.h>
#include <dzproperty.h>
#include <dzobject.h>
#include <dzpresentation.h>
#include <dznumericproperty.h>
#include <dzimageproperty.h>
#include <dzcolorproperty.h>
#include <dpcimages.h>
#include <dzfigure.h>
#include <dzfacetmesh.h>
#include <dzbone.h>
#include <dzcontentmgr.h>
//#include <dznodeinstance.h>
#include "idzsceneasset.h"
#include "dzuri.h"

#include "DzBridgeScriptableAction.h"
#include "DzBridgeDialog.h"
#include "DzBridgeMorphSelectionDialog.h"
#include "DzBridgeSubdivisionDialog.h"

DzBridgeScriptableAction::DzBridgeScriptableAction() :
	 DzBridgeAction(tr("Daz &Scriptable Bridge"), tr("Send the selected node to Daz Scriptable Bridge."))
{
     m_nNonInteractiveMode = 0;
	 m_sAssetType = QString("SkeletalMesh");
	 //Setup Icon
	 //QString iconName = "icon";
	 //QPixmap basePixmap = QPixmap::fromImage(getEmbeddedImage(iconName.toLatin1()));
	 //QIcon icon;
	 //icon.addPixmap(basePixmap, QIcon::Normal, QIcon::Off);
	 //QAction::setIcon(icon);

	 m_bGenerateNormalMaps = false;
}

void DzBridgeScriptableAction::executeAction()
{
	 // Check if the main window has been created yet.
	 // If it hasn't, alert the user and exit early.
	 DzMainWindow* mw = dzApp->getInterface();
	 if (!mw)
	 {
         if (m_nNonInteractiveMode == 0) 
		 {
             QMessageBox::warning(0, tr("Error"),
                 tr("The main window has not been created yet."), QMessageBox::Ok);
         }
		 return;
	 }

	 // Create and show the dialog. If the user cancels, exit early,
	 // otherwise continue on and do the thing that required modal
	 // input from the user.
    if (dzScene->getNumSelectedNodes() != 1)
    {
        if (m_nNonInteractiveMode == 0) 
		{
            QMessageBox::warning(0, tr("Error"),
                tr("Please select one Character or Prop to send."), QMessageBox::Ok);
        }
        return;
    }

    // Create the dialog
	if (m_bridgeDialog == nullptr)
	{
		m_bridgeDialog = new DzBridgeDialog(mw, QString(tr("Daz Scriptable Bridge")));
	}

	// Prepare member variables when not using GUI
	if (m_nNonInteractiveMode == 1)
	{
//		if (m_sRootFolder != "") m_bridgeDialog->getIntermediateFolderEdit()->setText(m_sRootFolder);

		if (m_aMorphListOverride.isEmpty() == false)
		{
			m_bEnableMorphs = true;
			m_sMorphSelectionRule = m_aMorphListOverride.join("\n1\n");
			m_sMorphSelectionRule += "\n1\n.CTRLVS\n2\nAnything\n0";
			if (m_morphSelectionDialog == nullptr)
			{
				m_morphSelectionDialog = DzBridgeMorphSelectionDialog::Get(m_bridgeDialog);
			}
			m_mMorphNameToLabel.clear();
			foreach(QString morphName, m_aMorphListOverride)
			{
				QString label = m_morphSelectionDialog->GetMorphLabelFromName(morphName);
				m_mMorphNameToLabel.insert(morphName, label);
			}
		}
		else
		{
			m_bEnableMorphs = false;
			m_sMorphSelectionRule = "";
			m_mMorphNameToLabel.clear();
		}

	}

    // If the Accept button was pressed, start the export
    int dialog_choice = -1;
	if (m_nNonInteractiveMode == 0)
	{
		dialog_choice = m_bridgeDialog->exec();
	}
    if (m_nNonInteractiveMode == 1 || dialog_choice == QDialog::Accepted)
    {
		// Read in Common GUI values
		readGui(m_bridgeDialog);

		exportHD();
    }
}

void DzBridgeScriptableAction::writeConfiguration()
{
	 QString DTUfilename = m_sDestinationPath + m_sAssetName + ".dtu";
	 QFile DTUfile(DTUfilename);
	 DTUfile.open(QIODevice::WriteOnly);
	 DzJsonWriter writer(&DTUfile);
	 writer.startObject(true);

	 writeDTUHeader(writer);

	 if (m_sAssetType.toLower().contains("mesh"))
	 {
		 QTextStream *pCVSStream = nullptr;
		 if (m_bExportMaterialPropertiesCSV)
		 {
			 QString filename = m_sDestinationPath + m_sAssetName + "_Maps.csv";
			 QFile file(filename);
			 file.open(QIODevice::WriteOnly);
			 pCVSStream = new QTextStream(&file);
			 *pCVSStream << "Version, Object, Material, Type, Color, Opacity, File" << endl;
		 }
		 writeAllMaterials(m_pSelectedNode, writer, pCVSStream);
		 writeAllMorphs(writer);
		 writeAllSubdivisions(writer);
		 writeAllDforceInfo(m_pSelectedNode, writer);
	 }

	 if (m_sAssetType == "Pose")
	 {
		writeAllPoses(writer);
	 }

	 if (m_sAssetType == "Environment")
	 {
		 writeEnvironment(writer);
	 }

	 writer.finishObject();
	 DTUfile.close();

}

// Setup custom FBX export options
void DzBridgeScriptableAction::setExportOptions(DzFileIOSettings& ExportOptions)
{

}

// Overrides baseclass implementation with Unreal specific resets
// Resets Default Values but Ignores any saved settings
void DzBridgeScriptableAction::resetToDefaults()
{
	DzBridgeAction::resetToDefaults();

	// Must Instantiate m_bridgeDialog so that we can override any saved states
	if (m_bridgeDialog == nullptr)
	{
		DzMainWindow* mw = dzApp->getInterface();
		m_bridgeDialog = new DzBridgeDialog(mw);
	}
	m_bridgeDialog->resetToDefaults();

	if (m_subdivisionDialog != nullptr)
	{
		foreach(QObject * obj, m_subdivisionDialog->getSubdivisionCombos())
		{
			QComboBox* combo = qobject_cast<QComboBox*>(obj);
			if (combo)
				combo->setCurrentIndex(0);
		}
	}
	// reset morph selection
	//DzBridgeMorphSelectionDialog::Get(nullptr)->PrepareDialog();

}

QString DzBridgeScriptableAction::readGuiRootFolder()
{
	return QString("");
}

#include "moc_DzBridgeScriptableAction.cpp"
