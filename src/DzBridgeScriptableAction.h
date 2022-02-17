#pragma once
#include <dzaction.h>
#include <dznode.h>
#include <dzgeometry.h>
#include <dzfigure.h>
#include <dzjsonwriter.h>
#include <QtCore/qfile.h>
#include <QtCore/qtextstream.h>
#include <QUuid.h>
#include <DzBridgeAction.h>

class DzBridgeDialog;

class DzBridgeScriptableAction : public DzBridgeAction {
	Q_OBJECT
public:
	DzBridgeScriptableAction();

	 Q_INVOKABLE void resetToDefaults();
	 QString readGUIRootFolder();

protected:
	 void executeAction();
	 Q_INVOKABLE void WriteConfiguration();
	 void SetExportOptions(DzFileIOSettings& ExportOptions);

};
