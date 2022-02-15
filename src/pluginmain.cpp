#include "dzplugin.h"
#include "dzapp.h"

#include "common_version.h"
#include "DzBridgeDialog.h"
#include "DzBridgeMorphSelectionDialog.h"
#include "DzBridgeSubdivisionDialog.h"
#include "OpenFBXInterface.h"

#ifdef __APPLE__
DZ_PLUGIN_DEFINITION("Daz Bridges Common Library");
#else
BOOL WINAPI DllMain(HINSTANCE hinstDLL, ULONG fdwReason, LPVOID lpvReserved)	
{	
	switch (fdwReason) {
	case DLL_PROCESS_ATTACH:
			break;
	case DLL_THREAD_ATTACH:
			break;
	case DLL_THREAD_DETACH:
			break;
	case DLL_PROCESS_DETACH:
			break;
	}
	return TRUE;
}
static DzPlugin s_pluginDef("Daz Bridges Common Library"); 
extern "C" __declspec(dllexport) DzVersion getSDKVersion() { return DZ_SDK_VERSION; }
extern "C" __declspec(dllexport) DzPlugin * getPluginDefinition() { return &s_pluginDef; }
#endif

DZ_PLUGIN_AUTHOR("Daz 3D, Inc");

DZ_PLUGIN_VERSION(COMMON_MAJOR, COMMON_MINOR, COMMON_REV, COMMON_BUILD);

DZ_PLUGIN_DESCRIPTION(QString(
"<b>Pre-Release Daz Bridge Library v%1.%2.%3.%4 </b><br>\
Bridge Collaboration Project<br><br>\
<a href = \"https://github.com/danielbui78-bridge-collab/DazToRuntime/tree/dzbridge-library-main\">Github</a><br><br>"
).arg(COMMON_MAJOR).arg(COMMON_MINOR).arg(COMMON_REV).arg(COMMON_BUILD));

DZ_PLUGIN_CUSTOM_CLASS_GUID(DzBridgeMorphSelectionDialog, 321916ba-0bcc-45d9-8c7e-ebbe80dea51c);
DZ_PLUGIN_CUSTOM_CLASS_GUID(DzBridgeSubdivisionDialog, a2342e17-db3b-4032-a576-75b5843fa893);
DZ_PLUGIN_CLASS_GUID(OpenFBXInterface, 9aaaf080-28c1-4e0f-a3e9-a0205e91a154);

static QWidget* GetParentArg0(const QVariantList& args)
{
	QWidget* parent = nullptr;
	QVariant qvar = args[0];
	QObject* obj = qvar.value<QObject*>();
	if (obj && obj->inherits("QWidget"))
	{
		parent = (QWidget*)obj;
	}

	return parent;
}

QObject* DzBridgeMorphSelectionDialogFactory::createInstance(const QVariantList& args) const
{
	QWidget* parent = GetParentArg0(args);
	return (QObject*) new DzBridgeMorphSelectionDialog(parent);
}
QObject* DzBridgeMorphSelectionDialogFactory::createInstance() const
{
	return (QObject*) new DzBridgeMorphSelectionDialog(nullptr);
}

QObject* DzBridgeSubdivisionDialogFactory::createInstance(const QVariantList& args) const
{
	QWidget* parent = GetParentArg0(args);
	return (QObject*) new DzBridgeSubdivisionDialog(parent);
}
QObject* DzBridgeSubdivisionDialogFactory::createInstance() const
{
	return (QObject*) new DzBridgeSubdivisionDialog(nullptr);
}
