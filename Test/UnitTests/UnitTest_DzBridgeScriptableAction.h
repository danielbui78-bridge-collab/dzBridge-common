#pragma once
#ifdef UNITTEST_DZBRIDGE

#include <QObject>
#include "UnitTest.h"

class DzBridgeScriptableAction;

class UnitTest_DzBridgeScriptableAction : public UnitTest {
	Q_OBJECT
public:
	UnitTest_DzBridgeScriptableAction();

	bool runUnitTests();

private:
	DzBridgeScriptableAction* m_testObject;

	bool unitTest001_DzBridgeAction();
	bool unitTest002_resetToDefaults();
	bool unitTest003_cleanString();
	bool unitTest004_getAvailableMorphs();
	bool unitTest005_getActiveMorphs();
	bool unitTest006_makeNormalMapFromHeightMap();
	bool unitTest007_preProcessScene();
	bool unitTest008_renameDuplicateMaterial();
	bool unitTest009_undoRenameDuplicateMaterials();
	bool unitTest010_generateMissingNormalMap();
	bool unitTest011_undoGenerateMissingNormalMaps();
	bool unitTest012_getActionGroup();
	bool unitTest013_getDefaultMenuPath();
	bool unitTest014_Export();
	bool unitTest015_ExportNode();
	bool unitTest016_WriteConfiguration();
	bool unitTest017_SetExportOptions();
	bool unitTest018_readGUIRootFolder();
	bool unitTest019_writeDTUHeader();
	bool unitTest020_startMaterialBlock();
	bool unitTest021_finishMaterialBlock();
	bool unitTest022_writeMaterialProperty();
	bool unitTest023_writeAllMorphs();
	bool unitTest024_writeMorphProperties();
	bool unitTest025_writeMorphJointLinkInfo();
	bool unitTest026_writeAllSubdivisionProperties();
	bool unitTest027_writeAllDForceInfo();
	bool unitTest028_writeDforceMaterialProperties();
	bool unitTest029_writeDforceModifiers();
	bool unitTest030_writeEnvironment();
	bool unitTest031_writeInstances();
	bool unitTest032_writeInstance();
	bool unitTest033_writeAllPoses();
	bool unitTest034_RenameDuplciateMaterials();
	bool unitTest035_UndoRenameDuplicateMaterials();
	bool unitTest036_GetScenePropList();
	bool unitTest037_DisconnectNode();
	bool unitTest038_ReconnectNodes();
	bool unitTest039_DisconnectOverrideControllers();
	bool unitTest040_ReconnectOverrideControllers();
	bool unitTest041_CheckIfPoseExportIsDestructive();
	bool unitTest042_UnlockTransform();
	bool unitTest043_getBridgeDialog();
	bool unitTest044_setBridgeDialog();
	bool unitTest045_getSubdivisionDialog();
	bool unitTest046_setSubdivisionDialog();
	bool unitTest047_getMorphSelectionDialog();
	bool unitTest048_getAssetType();
	bool unitTest049_setAssetType();
	bool unitTest050_getExportFilename();
	bool unitTest051_setExportFilename();
	bool unitTest052_getExportFolder();
	bool unitTest053_setExportFolder();
	bool unitTest054_getRootFolder();
	bool unitTest055_setRootFolder();
	bool unitTest056_getProductName();
	bool unitTest057_setProductName();
	bool unitTest058_getProductComponentName();
	bool unitTest059_setProductComponentName();
	bool unitTest060_getMorphList();
	bool unitTest061_setMorphList();
	bool unitTest062_getUseRelativePaths();
	bool unitTest063_setUseRelativePaths();
	bool unitTest064_isTemporaryFile();
	bool unitTest065_exportAssetWithDTU();
	bool unitTest066_writeJSON_Property_Texture();
	bool unitTest067_makeUniqueFilename();
	bool unitTest068_getUndoNormalMaps();
	bool unitTest069_setUndoNormalMaps();
	bool unitTest070_getNonInteractiveMode();
	bool unitTest071_setNonInteractiveMode();
	bool unitTest072_getExportFbx();
	bool unitTest073_setExportFbx();
	bool unitTest074_readGUI();
	bool unitTest075_exportHD();
	bool unitTest076_upgradeToHD();
	bool unitTest077_WriteWeightMaps();
	bool unitTest078_metaInvokeMethod();
	bool unitTest079_CopyFile();
	bool unitTest080_GetMD5();

};

#endif