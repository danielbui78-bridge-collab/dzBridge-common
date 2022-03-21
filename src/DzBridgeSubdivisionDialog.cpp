#include <QtGui/QLayout>
#include <QtGui/QLabel>
#include <QtGui/QGroupBox>
#include <QtGui/QPushButton>
#include <QtGui/QToolTip>
#include <QtGui/QWhatsThis>
#include <QtGui/qlineedit.h>
#include <QtGui/qboxlayout.h>
#include <QtGui/qfiledialog.h>
#include <QtCore/qsettings.h>
#include <QtGui/qformlayout.h>
#include <QtGui/qcombobox.h>
#include <QtGui/qdesktopservices.h>
#include <QtGui/qlistwidget.h>
#include <QtGui/qtreewidget.h>
#include <QtGui/qcheckbox.h>
#include <QtGui/qdesktopservices.h>
#include <QtCore/qdiriterator.h>
#include "QtCore/qfile.h"
#include "QtCore/qtextstream.h"

#include "dzapp.h"
#include "dzscene.h"
#include "dzstyle.h"
#include "dzmainwindow.h"
#include "dzactionmgr.h"
#include "dzaction.h"
#include "dzskeleton.h"
#include "dzobject.h"
#include "dzshape.h"
#include "dzmodifier.h"
#include "dzpresentation.h"
#include "dzassetmgr.h"
#include "dzproperty.h"
#include "dznumericnodeproperty.h"
#include "dzsettings.h"
#include "dzmorph.h"
#include "dzgeometry.h"

#include "DzBridgeSubdivisionDialog.h"

#include "QtGui/qlayout.h"
#include "QtGui/qlineedit.h"

#include <QtCore/QDebug.h>

/*****************************
Local definitions
*****************************/
#define DAZ_BRIDGE_LIBRARY_NAME "Daz Bridge"

using namespace DzUnreal;

CPP_Export DzBridgeSubdivisionDialog* DzBridgeSubdivisionDialog::singleton = nullptr;

DzBridgeSubdivisionDialog::DzBridgeSubdivisionDialog(QWidget *parent) :
	DzBasicDialog(parent, DAZ_BRIDGE_LIBRARY_NAME)
{
	 subdivisionItemsGrid = NULL;
	//settings = new QSettings("Code Wizards", "DazToUnreal");



	// Set the dialog title 
	setWindowTitle(tr("Choose Subdivision Levels"));

	// Setup folder
	presetsFolder = QDesktopServices::storageLocation(QDesktopServices::DocumentsLocation) + QDir::separator() + "DazToUnreal" + QDir::separator() + "Presets";


	QVBoxLayout* mainLayout = new QVBoxLayout();
	mainLayout->addWidget(new QLabel("Subdivision can greatly increase transfer time."));

	subdivisionItemsGrid = new QGridLayout();
	subdivisionItemsGrid->addWidget(new QLabel("Object Name"), 0, 0);
	subdivisionItemsGrid->addWidget(new QLabel("Subdivision Level"), 0, 1);
	subdivisionItemsGrid->addWidget(new QLabel("Base Vert Count"), 0, 2);
	mainLayout->addLayout(subdivisionItemsGrid);
	mainLayout->addStretch();

	this->addLayout(mainLayout);
	resize(QSize(800, 800));//.expandedTo(minimumSizeHint()));
	setFixedWidth(width());
	setFixedHeight(height());

	SubdivisionCombos.clear();

	PrepareDialog();
}

QSize DzBridgeSubdivisionDialog::minimumSizeHint() const
{
	return QSize(800, 800);
}


void DzBridgeSubdivisionDialog::PrepareDialog()
{
	/*foreach(QObject* object, this->children())
	{
		delete object;
	}*/

	/*if (this->layout())
	{
		delete this->layout();
	}


	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(new QLabel("Subdivision can greatly increase transfer time."));*/

	int itemCount = subdivisionItemsGrid->count();
	while(QLayoutItem* item = subdivisionItemsGrid->takeAt(0))
	{
		if (QWidget* widget = item->widget())
		{
			delete widget;
			//delete item;
		}
	}

	//subdivisionItemsGrid = new QGridLayout(this);
	subdivisionItemsGrid->addWidget(new QLabel("Object Name"), 0, 0);
	subdivisionItemsGrid->addWidget(new QLabel("Subdivision Level"), 0, 1);
	subdivisionItemsGrid->addWidget(new QLabel("Base Vert Count"), 0, 2);
	//mainLayout->addLayout(subdivisionItemsGrid);
	//mainLayout->addStretch();

	//this->addLayout(mainLayout);
	//resize(QSize(800, 800));//.expandedTo(minimumSizeHint()));
	//setFixedWidth(width());
	//setFixedHeight(height());

	SubdivisionCombos.clear();
	DzNode* Selection = dzScene->getPrimarySelection();
	CreateList(Selection);
}

void DzBridgeSubdivisionDialog::CreateList(DzNode* Node)
{
	DzObject* Object = Node->getObject();
	if (Object)
	{
		DzShape* Shape = Object ? Object->getCurrentShape() : NULL;
		DzGeometry* Geo = Shape ? Shape->getGeometry() : NULL;
		
		int row = subdivisionItemsGrid->rowCount();
		subdivisionItemsGrid->addWidget(new QLabel(Node->getLabel()), row, 0);
		QComboBox* subdivisionLevelCombo = new QComboBox(this);
		subdivisionLevelCombo->setProperty("Object", QVariant(Node->getName()));
		subdivisionLevelCombo->addItem("0");
		subdivisionLevelCombo->addItem("1");
		subdivisionLevelCombo->addItem("2");
		subdivisionLevelCombo->addItem("3");
		subdivisionLevelCombo->addItem("4");
		SubdivisionCombos.append(subdivisionLevelCombo);
		subdivisionItemsGrid->addWidget(subdivisionLevelCombo, row, 1);
		if (SubdivisionLevels.contains(Node->getName()))
		{
			subdivisionLevelCombo->setCurrentIndex(SubdivisionLevels[Node->getName()]);
		}
		connect(subdivisionLevelCombo, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(HandleSubdivisionLevelChanged(const QString &)));

		if (Geo)
		{
			int VertCount = Geo->getNumVertices();
			subdivisionItemsGrid->addWidget(new QLabel(QString::number(VertCount)), row, 2);

			/*for (int index = 0; index < Shape->getNumProperties(); index++)
			{
				DzProperty* property = Shape->getProperty(index);
				QString propName = property->getName();//property->getName();
				QString propLabel = property->getLabel();
				qDebug() << propName << " " << propLabel;
			}*/
		}
	}

	for (int ChildIndex = 0; ChildIndex < Node->getNumNodeChildren(); ChildIndex++)
	{
		DzNode* ChildNode = Node->getNodeChild(ChildIndex);
		CreateList(ChildNode);
	}
}

void DzBridgeSubdivisionDialog::HandleSubdivisionLevelChanged(const QString& text)
{
	foreach(QComboBox* combo, SubdivisionCombos)
	{
		QString name = combo->property("Object").toString();
		int targetValue = combo->currentText().toInt();
		SubdivisionLevels[name] = targetValue;
	}
}

DzNode* DzBridgeSubdivisionDialog::FindObject(DzNode* Node, QString Name)
{
	if (Node == nullptr)
		return nullptr;

	DzObject* Object = Node->getObject();
	if (Object)
	{
		if (Node->getName() == Name) return Node;
	}

	for (int ChildIndex = 0; ChildIndex < Node->getNumNodeChildren(); ChildIndex++)
	{
		DzNode* ChildNode = Node->getNodeChild(ChildIndex);
		DzNode* FoundNode = FindObject(ChildNode, Name);
		if (FoundNode) return FoundNode;
	}
	return NULL;
}

bool DzBridgeSubdivisionDialog::setSubdivisionLevelByNode(DzNode* Node, int level)
{
	if (Node == nullptr)
		return nullptr;

	DzNode* selection = dzScene->getPrimarySelection();
	QString searchName = Node->getName();
	foreach(QComboBox * combo, SubdivisionCombos)
	{
		QString name = combo->property("Object").toString();
		if (name == searchName)
		{
			int maxLevel = combo->count() - 1;
			if (level > maxLevel)
				return false;

			combo->setCurrentIndex(level);
			return true;
		}
	}

	return false;
}

void DzBridgeSubdivisionDialog::LockSubdivisionProperties(bool subdivisionEnabled)
{
	DzNode* Selection = dzScene->getPrimarySelection();
	foreach(QComboBox* combo, SubdivisionCombos)
	{
		QString Name = combo->property("Object").toString();
		DzNode* ObjectNode = FindObject(Selection, Name);
		if (ObjectNode)
		{
			DzObject* Object = ObjectNode->getObject();
			DzShape* Shape = Object ? Object->getCurrentShape() : NULL;
			DzGeometry* Geo = Shape ? Shape->getGeometry() : NULL;
			if (Geo)
			{
				int VertCount = Geo->getNumVertices();

				for (int index = 0; index < Shape->getNumProperties(); index++)
				{
					DzProperty* property = Shape->getProperty(index);
					DzNumericProperty* numericProperty = qobject_cast<DzNumericProperty*>(property);
					QString propName = property->getName();
					if (propName == "SubDIALevel" && numericProperty)
					{
						// DB 2021-09-02: Record data to Unlock/Undo changes
						UndoData undo_data;
						undo_data.originalLockState = numericProperty->isLocked();
						undo_data.originalValue = numericProperty->getDoubleValue();
						UndoSubdivisionOverrides.insert(numericProperty, undo_data);

						numericProperty->lock(false);
						if (subdivisionEnabled)
						{
							double targetValue = combo->currentText().toDouble();
							numericProperty->setDoubleValue(targetValue);
						}
						else
						{
							numericProperty->setDoubleValue(0.0f);
						}
						numericProperty->lock(true);
					}
					//QString propLabel = property->getLabel();
					//qDebug() << propName << " " << propLabel;
				}
			}
		}
	}
}

// DB 2021-09-02: Unlock/Undo Subdivision Property Changes
void DzBridgeSubdivisionDialog::UnlockSubdivisionProperties()
{
	QMap<DzProperty*, UndoData>::iterator undoIterator = UndoSubdivisionOverrides.begin();
	while (undoIterator != UndoSubdivisionOverrides.end())
	{
		DzProperty* undoKey = undoIterator.key();
		DzNumericProperty* numericProperty = qobject_cast<DzNumericProperty*>(undoKey);
		if (numericProperty)
		{
			UndoData undo_data = undoIterator.value();
			numericProperty->lock(false);
			numericProperty->setDoubleValue(undo_data.originalValue);
			numericProperty->lock(undo_data.originalLockState);
		}
		undoIterator++;
	}

	// Clear subdivision map after processing undo
	UndoSubdivisionOverrides.clear();
}

// DEPRECATED: use DzBridgeAction::writeAllSubdivisions(DzJsonWriter& writer)
void DzBridgeSubdivisionDialog::WriteSubdivisions(DzJsonWriter& Writer)
{
	DzNode* Selection = dzScene->getPrimarySelection();

	//stream << "Version, Object, Subdivision" << endl;
	foreach(QComboBox* combo, SubdivisionCombos)
	{
		QString Name = combo->property("Object").toString() + ".Shape";
		//DzNode* ObjectNode = FindObject(Selection, Name);

		int targetValue = combo->currentText().toInt();
		Writer.startObject(true);
		Writer.addMember("Version", 1);
		Writer.addMember("Asset Name", Name);
		Writer.addMember("Value", targetValue);
		Writer.finishObject();
		//stream << "1, " << Name << ", " << targetValue << endl;
	}
}

QObjectList DzBridgeSubdivisionDialog::getSubdivisionCombos()
{
	QObjectList *returnList = new QObjectList();
	foreach(QComboBox * combo, SubdivisionCombos)
	{
		returnList->append(qobject_cast<QWidget*>(combo));
	}
	return *returnList;
}

std::map<std::string, int>* DzBridgeSubdivisionDialog::GetLookupTable()
{
	std::map<std::string, int>* pLookupTable = new std::map<std::string, int>();

	foreach(QComboBox * combo, SubdivisionCombos)
	{
		std::string name(combo->property("Object").toString().toLocal8Bit().data());
		name = name + ".Shape";
		int targetValue = combo->currentText().toInt();
		(*pLookupTable)[name] = targetValue;

	}

	return pLookupTable;
}

#include "moc_DzBridgeSubdivisionDialog.cpp"
