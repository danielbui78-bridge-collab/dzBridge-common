#pragma once
#include "dzbasicdialog.h"
#include <QtGui/qcombobox.h>
#include <QtCore/qsettings.h>

class QPushButton;
class QLineEdit;
class QCheckBox;
class QComboBox;
class QGroupBox;
class QFormLayout;

#undef DLLExport
#define DLLExport Q_DECL_IMPORT
#ifdef DZ_BRIDGE_SHARED
	#undef DLLExport
	#define DLLExport Q_DECL_EXPORT
#elif DZ_BRIDGE_STATIC
	#undef DLLExport
	#define DLLExport
#endif

class DLLExport DzBridgeDialog : public DzBasicDialog {
	Q_OBJECT
	Q_PROPERTY(QWidget* wAssetNameEdit READ getAssetNameEdit)
	Q_PROPERTY(QWidget* wAssetTypeCombo READ getAssetTypeCombo)
	Q_PROPERTY(QWidget* wMorphsEnabledCheckBox READ getMorphsEnabledCheckBox)
	Q_PROPERTY(QWidget* wSubdivisionEnabledCheckBox READ getSubdivisionEnabledCheckBox)
	Q_PROPERTY(QWidget* wAdvancedSettingsGroupBox READ getAdvancedSettingsGroupBox)
	Q_PROPERTY(QWidget* wFbxVersionCombo READ getFbxVersionCombo)
	Q_PROPERTY(QWidget* wShowFbxDialogCheckBox READ getShowFbxDialogCheckBox)
public:
	Q_INVOKABLE QLineEdit* getAssetNameEdit() { return assetNameEdit; }
	Q_INVOKABLE QComboBox* getAssetTypeCombo() { return assetTypeCombo; }
	Q_INVOKABLE QCheckBox* getMorphsEnabledCheckBox() { return morphsEnabledCheckBox; }
	Q_INVOKABLE QCheckBox* getSubdivisionEnabledCheckBox() { return subdivisionEnabledCheckBox; }
	Q_INVOKABLE QGroupBox* getAdvancedSettingsGroupBox() { return advancedSettingsGroupBox; }
	Q_INVOKABLE QComboBox* getFbxVersionCombo() { return fbxVersionCombo; }
	Q_INVOKABLE QCheckBox* getShowFbxDialogCheckBox() { return showFbxDialogCheckBox; }

	/** Constructor **/
	 DzBridgeDialog(QWidget *parent=nullptr, const QString &windowTitle="");

	/** Destructor **/
	virtual ~DzBridgeDialog() {}

	// Pass so the DazTRoUnrealAction can access it from the morph dialog
	Q_INVOKABLE QString GetMorphString();
	// Pass so the DazTRoUnrealAction can access it from the morph dialog
	Q_INVOKABLE QMap<QString,QString> GetMorphMapping() { return morphMapping; }
	Q_INVOKABLE virtual void resetToDefaults();
	Q_INVOKABLE bool loadSavedSettings();

	void Accepted();

protected slots:
	void handleSceneSelectionChanged();
	void HandleChooseMorphsButton();
	void HandleMorphsCheckBoxChange(int state);
	void HandleChooseSubdivisionsButton();
	void HandleSubdivisionCheckBoxChange(int state);
	void HandleFBXVersionChange(const QString& fbxVersion);
	void HandleShowFbxDialogCheckBoxChange(int state);
	void HandleExportMaterialPropertyCSVCheckBoxChange(int state);
	void HandleShowAdvancedSettingsCheckBoxChange(bool checked);

protected:
	QSettings* settings;

	void refreshAsset();

	// These are clumsy leftovers from before the dialog were singletons
	QString morphString;
	QMap<QString,QString> morphMapping;

	QFormLayout* mainLayout;
	QFormLayout* advancedLayout;
	QLineEdit* assetNameEdit;
	//	QLineEdit* projectEdit;
	//	QPushButton* projectButton;
	QComboBox* assetTypeCombo;
	QPushButton* morphsButton;
	QCheckBox* morphsEnabledCheckBox;
	QPushButton* subdivisionButton;
	QCheckBox* subdivisionEnabledCheckBox;
	QGroupBox* advancedSettingsGroupBox;
	QWidget* advancedWidget;
	QComboBox* fbxVersionCombo;
	QCheckBox* showFbxDialogCheckBox;


};
