#pragma once
#include <dzaction.h>
#include <dznode.h>
#include <dzgeometry.h>
#include <dzfigure.h>
#include <dzjsonwriter.h>
#include <QtCore/qfile.h>
#include <QtCore/qtextstream.h>
#include <QUuid.h>
#include <DzRuntimePluginAction.h>

class DzBridgeDialog;

class DzBridgeScriptableAction : public DzRuntimePluginAction {
	Q_OBJECT
	Q_PROPERTY(DzBasicDialog* wBridgeDialog READ getBridgeDialog WRITE setBridgeDialog)
public:
	DzBridgeScriptableAction();

	 Q_INVOKABLE DzBridgeDialog* getBridgeDialog() { return BridgeDialog; }
	 Q_INVOKABLE bool setBridgeDialog(DzBasicDialog* arg_dlg);

	 Q_INVOKABLE void resetToDefaults();
	 QString readGUIRootFolder();
protected:
	 DzBridgeDialog *BridgeDialog;

	 void executeAction();
	 Q_INVOKABLE void WriteConfiguration();
	 void SetExportOptions(DzFileIOSettings& ExportOptions);

};
