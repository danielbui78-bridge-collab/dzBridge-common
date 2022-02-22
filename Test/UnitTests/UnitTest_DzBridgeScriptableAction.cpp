#ifdef UNITTEST_DZBRIDGE

#include "UnitTest_DzBridgeScriptableAction.h"
#include "DzBridgeScriptableAction.h"


/// <summary>
/// Constructor
/// </summary>
UnitTest_DzBridgeScriptableAction::UnitTest_DzBridgeScriptableAction()
{
	m_testObject = (QObject*) new DzBridgeScriptableAction();
}

/// <summary>
/// This class also tests DzBridgeAction indirectly since DzBridgeAction is an abstract base class.
/// </summary>
/// <returns></returns>
bool UnitTest_DzBridgeScriptableAction::runUnitTests()
{
	if (!m_testObject)
	{
		return false;
	}

	RUNTEST(unitTest001_DzBridgeAction);
	RUNTEST(unitTest002_resetToDefaults);
	RUNTEST(unitTest003_cleanString);
	RUNTEST(unitTest004_getAvailableMorphs);
	RUNTEST(unitTest005_getActiveMorphs);
	RUNTEST(unitTest006_makeNormalMapFromHeightMap);
	RUNTEST(unitTest007_preProcessScene);
	RUNTEST(unitTest008_renameDuplicateMaterial);
	RUNTEST(unitTest009_undoRenameDuplicateMaterials);
	RUNTEST(unitTest010_generateMissingNormalMap);
	RUNTEST(unitTest011_undoGenerateMissingNormalMaps);
	RUNTEST(unitTest012_getActionGroup);
	RUNTEST(unitTest013_getDefaultMenuPath);
	RUNTEST(unitTest014_Export);
	RUNTEST(unitTest015_ExportNode);
	RUNTEST(unitTest016_WriteConfiguration);
	RUNTEST(unitTest017_SetExportOptions);
	RUNTEST(unitTest018_readGUIRootFolder);
	RUNTEST(unitTest019_writeDTUHeader);
	RUNTEST(unitTest020_startMaterialBlock);
	RUNTEST(unitTest021_finishMaterialBlock);
	RUNTEST(unitTest022_writeMaterialProperty);
	RUNTEST(unitTest023_writeAllMorphs);
	RUNTEST(unitTest024_writeMorphProperties);
	RUNTEST(unitTest025_writeMorphJointLinkInfo);
	RUNTEST(unitTest026_writeAllSubdivisionProperties);
	RUNTEST(unitTest027_writeAllDForceInfo);
	RUNTEST(unitTest028_writeDforceMaterialProperties);
	RUNTEST(unitTest029_writeDforceModifiers);
	RUNTEST(unitTest030_writeEnvironment);
	RUNTEST(unitTest031_writeInstances);
	RUNTEST(unitTest032_writeInstance);
	RUNTEST(unitTest033_writeAllPoses);
	RUNTEST(unitTest034_RenameDuplciateMaterials);
	RUNTEST(unitTest035_UndoRenameDuplicateMaterials);
	RUNTEST(unitTest036_GetScenePropList);
	RUNTEST(unitTest037_DisconnectNode);
	RUNTEST(unitTest038_ReconnectNodes);
	RUNTEST(unitTest039_DisconnectOverrideControllers);
	RUNTEST(unitTest040_ReconnectOverrideControllers);
	RUNTEST(unitTest041_CheckIfPoseExportIsDestructive);
	RUNTEST(unitTest042_UnlockTransform);
	RUNTEST(unitTest043_getBridgeDialog);
	RUNTEST(unitTest044_setBridgeDialog);
	RUNTEST(unitTest045_getSubdivisionDialog);
	RUNTEST(unitTest046_setSubdivisionDialog);
	RUNTEST(unitTest047_getMorphSelectionDialog);
	RUNTEST(unitTest048_getAssetType);
	RUNTEST(unitTest049_setAssetType);
	RUNTEST(unitTest050_getExportFilename);
	RUNTEST(unitTest051_setExportFilename);
	RUNTEST(unitTest052_getExportFolder);
	RUNTEST(unitTest053_setExportFolder);
	RUNTEST(unitTest054_getRootFolder);
	RUNTEST(unitTest055_setRootFolder);
	RUNTEST(unitTest056_getProductName);
	RUNTEST(unitTest057_setProductName);
	RUNTEST(unitTest058_getProductComponentName);
	RUNTEST(unitTest059_setProductComponentName);
	RUNTEST(unitTest060_getMorphList);
	RUNTEST(unitTest061_setMorphList);
	RUNTEST(unitTest062_getUseRelativePaths);
	RUNTEST(unitTest063_setUseRelativePaths);
	RUNTEST(unitTest064_isTemporaryFile);
	RUNTEST(unitTest065_exportAssetWithDTU);
	RUNTEST(unitTest066_writeJSON_Property_Texture);
	RUNTEST(unitTest067_makeUniqueFilename);
	RUNTEST(unitTest068_getUndoNormalMaps);
	RUNTEST(unitTest069_setUndoNormalMaps);
	RUNTEST(unitTest070_getNonInteractiveMode);
	RUNTEST(unitTest071_setNonInteractiveMode);
	RUNTEST(unitTest072_getExportFbx);
	RUNTEST(unitTest073_setExportFbx);
	RUNTEST(unitTest074_readGUI);
	RUNTEST(unitTest075_exportHD);
	RUNTEST(unitTest076_upgradeToHD);
	RUNTEST(unitTest077_WriteWeightMaps);
	RUNTEST(unitTest078_metaInvokeMethod);
	RUNTEST(unitTest079_CopyFile);
	RUNTEST(unitTest080_GetMD5);


	return true;
}

bool UnitTest_DzBridgeScriptableAction::unitTest001_DzBridgeAction(UnitTest::TestResult *testResult)
{
	LOGTEST_TEXT("Testing [UnitTest001 DzBridgeAction]");

	DzBridgeAction *testObj = new DzBridgeScriptableAction();

	if (!testObj)
	{
		LOGTEST_FAILED("");
	}

	LOGTEST_PASSED("");

	QString debug = QString("");

	debug = testResult->aLog->join("\n");
	
	return true;
}

bool UnitTest_DzBridgeScriptableAction::unitTest002_resetToDefaults(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest003_cleanString(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest004_getAvailableMorphs(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest005_getActiveMorphs(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest006_makeNormalMapFromHeightMap(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest007_preProcessScene(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest008_renameDuplicateMaterial(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest009_undoRenameDuplicateMaterials(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest010_generateMissingNormalMap(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest011_undoGenerateMissingNormalMaps(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest012_getActionGroup(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest013_getDefaultMenuPath(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest014_Export(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest015_ExportNode(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest016_WriteConfiguration(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest017_SetExportOptions(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest018_readGUIRootFolder(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest019_writeDTUHeader(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest020_startMaterialBlock(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest021_finishMaterialBlock(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest022_writeMaterialProperty(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest023_writeAllMorphs(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest024_writeMorphProperties(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest025_writeMorphJointLinkInfo(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest026_writeAllSubdivisionProperties(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest027_writeAllDForceInfo(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest028_writeDforceMaterialProperties(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest029_writeDforceModifiers(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest030_writeEnvironment(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest031_writeInstances(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest032_writeInstance(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest033_writeAllPoses(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest034_RenameDuplciateMaterials(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest035_UndoRenameDuplicateMaterials(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest036_GetScenePropList(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest037_DisconnectNode(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest038_ReconnectNodes(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest039_DisconnectOverrideControllers(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest040_ReconnectOverrideControllers(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest041_CheckIfPoseExportIsDestructive(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest042_UnlockTransform(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest043_getBridgeDialog(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest044_setBridgeDialog(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest045_getSubdivisionDialog(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest046_setSubdivisionDialog(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest047_getMorphSelectionDialog(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest048_getAssetType(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest049_setAssetType(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest050_getExportFilename(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest051_setExportFilename(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest052_getExportFolder(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest053_setExportFolder(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest054_getRootFolder(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest055_setRootFolder(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest056_getProductName(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest057_setProductName(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest058_getProductComponentName(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest059_setProductComponentName(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest060_getMorphList(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest061_setMorphList(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest062_getUseRelativePaths(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest063_setUseRelativePaths(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest064_isTemporaryFile(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest065_exportAssetWithDTU(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest066_writeJSON_Property_Texture(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest067_makeUniqueFilename(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest068_getUndoNormalMaps(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest069_setUndoNormalMaps(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest070_getNonInteractiveMode(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest071_setNonInteractiveMode(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest072_getExportFbx(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest073_setExportFbx(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest074_readGUI(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest075_exportHD(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest076_upgradeToHD(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest077_WriteWeightMaps(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest078_metaInvokeMethod(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest079_CopyFile(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest080_GetMD5(UnitTest::TestResult* testResult)
{
	return false;
}




#include "moc_UnitTest_DzBridgeScriptableAction.cpp"
#endif