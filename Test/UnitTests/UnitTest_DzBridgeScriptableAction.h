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
	bool unitTest001_DzBridgeAction(UnitTest::TestResult* testResult);
	bool unitTest002_resetToDefaults(UnitTest::TestResult* testResult);
	bool unitTest003_cleanString(UnitTest::TestResult* testResult);
	bool unitTest004_getAvailableMorphs(UnitTest::TestResult* testResult);
	bool unitTest005_getActiveMorphs(UnitTest::TestResult* testResult);
	bool unitTest006_makeNormalMapFromHeightMap(UnitTest::TestResult* testResult);
	bool unitTest007_preProcessScene(UnitTest::TestResult* testResult);
	bool unitTest008_renameDuplicateMaterial(UnitTest::TestResult* testResult);
	bool unitTest009_undoRenameDuplicateMaterials(UnitTest::TestResult* testResult);
	bool unitTest010_generateMissingNormalMap(UnitTest::TestResult* testResult);
	bool unitTest011_undoGenerateMissingNormalMaps(UnitTest::TestResult* testResult);
	bool unitTest012_getActionGroup(UnitTest::TestResult* testResult);
	bool unitTest013_getDefaultMenuPath(UnitTest::TestResult* testResult);
	bool unitTest014_Export(UnitTest::TestResult* testResult);
	bool unitTest015_ExportNode(UnitTest::TestResult* testResult);
	bool unitTest016_WriteConfiguration(UnitTest::TestResult* testResult);
	bool unitTest017_SetExportOptions(UnitTest::TestResult* testResult);
	bool unitTest018_readGUIRootFolder(UnitTest::TestResult* testResult);
	bool unitTest019_writeDTUHeader(UnitTest::TestResult* testResult);
	bool unitTest020_startMaterialBlock(UnitTest::TestResult* testResult);
	bool unitTest021_finishMaterialBlock(UnitTest::TestResult* testResult);
	bool unitTest022_writeMaterialProperty(UnitTest::TestResult* testResult);
	bool unitTest023_writeAllMorphs(UnitTest::TestResult* testResult);
	bool unitTest024_writeMorphProperties(UnitTest::TestResult* testResult);
	bool unitTest025_writeMorphJointLinkInfo(UnitTest::TestResult* testResult);
	bool unitTest026_writeAllSubdivisionProperties(UnitTest::TestResult* testResult);
	bool unitTest027_writeAllDForceInfo(UnitTest::TestResult* testResult);
	bool unitTest028_writeDforceMaterialProperties(UnitTest::TestResult* testResult);
	bool unitTest029_writeDforceModifiers(UnitTest::TestResult* testResult);
	bool unitTest030_writeEnvironment(UnitTest::TestResult* testResult);
	bool unitTest031_writeInstances(UnitTest::TestResult* testResult);
	bool unitTest032_writeInstance(UnitTest::TestResult* testResult);
	bool unitTest033_writeAllPoses(UnitTest::TestResult* testResult);
	bool unitTest034_RenameDuplciateMaterials(UnitTest::TestResult* testResult);
	bool unitTest035_UndoRenameDuplicateMaterials(UnitTest::TestResult* testResult);
	bool unitTest036_GetScenePropList(UnitTest::TestResult* testResult);
	bool unitTest037_DisconnectNode(UnitTest::TestResult* testResult);
	bool unitTest038_ReconnectNodes(UnitTest::TestResult* testResult);
	bool unitTest039_DisconnectOverrideControllers(UnitTest::TestResult* testResult);
	bool unitTest040_ReconnectOverrideControllers(UnitTest::TestResult* testResult);
	bool unitTest041_CheckIfPoseExportIsDestructive(UnitTest::TestResult* testResult);
	bool unitTest042_UnlockTransform(UnitTest::TestResult* testResult);
	bool unitTest043_getBridgeDialog(UnitTest::TestResult* testResult);
	bool unitTest044_setBridgeDialog(UnitTest::TestResult* testResult);
	bool unitTest045_getSubdivisionDialog(UnitTest::TestResult* testResult);
	bool unitTest046_setSubdivisionDialog(UnitTest::TestResult* testResult);
	bool unitTest047_getMorphSelectionDialog(UnitTest::TestResult* testResult);
	bool unitTest048_getAssetType(UnitTest::TestResult* testResult);
	bool unitTest049_setAssetType(UnitTest::TestResult* testResult);
	bool unitTest050_getExportFilename(UnitTest::TestResult* testResult);
	bool unitTest051_setExportFilename(UnitTest::TestResult* testResult);
	bool unitTest052_getExportFolder(UnitTest::TestResult* testResult);
	bool unitTest053_setExportFolder(UnitTest::TestResult* testResult);
	bool unitTest054_getRootFolder(UnitTest::TestResult* testResult);
	bool unitTest055_setRootFolder(UnitTest::TestResult* testResult);
	bool unitTest056_getProductName(UnitTest::TestResult* testResult);
	bool unitTest057_setProductName(UnitTest::TestResult* testResult);
	bool unitTest058_getProductComponentName(UnitTest::TestResult* testResult);
	bool unitTest059_setProductComponentName(UnitTest::TestResult* testResult);
	bool unitTest060_getMorphList(UnitTest::TestResult* testResult);
	bool unitTest061_setMorphList(UnitTest::TestResult* testResult);
	bool unitTest062_getUseRelativePaths(UnitTest::TestResult* testResult);
	bool unitTest063_setUseRelativePaths(UnitTest::TestResult* testResult);
	bool unitTest064_isTemporaryFile(UnitTest::TestResult* testResult);
	bool unitTest065_exportAssetWithDTU(UnitTest::TestResult* testResult);
	bool unitTest066_writeJSON_Property_Texture(UnitTest::TestResult* testResult);
	bool unitTest067_makeUniqueFilename(UnitTest::TestResult* testResult);
	bool unitTest068_getUndoNormalMaps(UnitTest::TestResult* testResult);
	bool unitTest069_setUndoNormalMaps(UnitTest::TestResult* testResult);
	bool unitTest070_getNonInteractiveMode(UnitTest::TestResult* testResult);
	bool unitTest071_setNonInteractiveMode(UnitTest::TestResult* testResult);
	bool unitTest072_getExportFbx(UnitTest::TestResult* testResult);
	bool unitTest073_setExportFbx(UnitTest::TestResult* testResult);
	bool unitTest074_readGUI(UnitTest::TestResult* testResult);
	bool unitTest075_exportHD(UnitTest::TestResult* testResult);
	bool unitTest076_upgradeToHD(UnitTest::TestResult* testResult);
	bool unitTest077_WriteWeightMaps(UnitTest::TestResult* testResult);
	bool unitTest078_metaInvokeMethod(UnitTest::TestResult* testResult);
	bool unitTest079_CopyFile(UnitTest::TestResult* testResult);
	bool unitTest080_GetMD5(UnitTest::TestResult* testResult);

};

#endif