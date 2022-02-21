#ifdef UNITTEST_DZBRIDGE

#include "UnitTest_DzBridgeScriptableAction.h"
#include "DzBridgeScriptableAction.h"


/// <summary>
/// Constructor
/// </summary>
UnitTest_DzBridgeScriptableAction::UnitTest_DzBridgeScriptableAction()
{
	m_testObject = nullptr;

}

/// <summary>
/// This class also tests DzBridgeAction indirectly since DzBridgeAction is an abstract base class.
/// </summary>
/// <returns></returns>
bool UnitTest_DzBridgeScriptableAction::runUnitTests()
{
	m_testObject = new DzBridgeScriptableAction();

	if (!m_testObject)
	{
		return false;
	}

	RUNTEST_1ARG(unitTest001_DzBridgeAction);
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
	LOGTEST_TEXT("Testing unitTest001_DzBridgeAction");

	DzBridgeAction *testObj = new DzBridgeScriptableAction();

	if (!testObj)
	{
		LOGTEST_FAILED("");
	}

	LOGTEST_PASSED("");

	printf(testResult->log->join("\n").toLocal8Bit().data() );
	return true;
}

bool UnitTest_DzBridgeScriptableAction::unitTest002_resetToDefaults()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest003_cleanString()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest004_getAvailableMorphs()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest005_getActiveMorphs()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest006_makeNormalMapFromHeightMap()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest007_preProcessScene()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest008_renameDuplicateMaterial()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest009_undoRenameDuplicateMaterials()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest010_generateMissingNormalMap()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest011_undoGenerateMissingNormalMaps()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest012_getActionGroup()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest013_getDefaultMenuPath()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest014_Export()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest015_ExportNode()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest016_WriteConfiguration()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest017_SetExportOptions()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest018_readGUIRootFolder()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest019_writeDTUHeader()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest020_startMaterialBlock()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest021_finishMaterialBlock()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest022_writeMaterialProperty()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest023_writeAllMorphs()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest024_writeMorphProperties()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest025_writeMorphJointLinkInfo()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest026_writeAllSubdivisionProperties()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest027_writeAllDForceInfo()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest028_writeDforceMaterialProperties()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest029_writeDforceModifiers()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest030_writeEnvironment()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest031_writeInstances()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest032_writeInstance()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest033_writeAllPoses()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest034_RenameDuplciateMaterials()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest035_UndoRenameDuplicateMaterials()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest036_GetScenePropList()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest037_DisconnectNode()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest038_ReconnectNodes()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest039_DisconnectOverrideControllers()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest040_ReconnectOverrideControllers()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest041_CheckIfPoseExportIsDestructive()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest042_UnlockTransform()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest043_getBridgeDialog()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest044_setBridgeDialog()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest045_getSubdivisionDialog()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest046_setSubdivisionDialog()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest047_getMorphSelectionDialog()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest048_getAssetType()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest049_setAssetType()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest050_getExportFilename()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest051_setExportFilename()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest052_getExportFolder()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest053_setExportFolder()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest054_getRootFolder()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest055_setRootFolder()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest056_getProductName()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest057_setProductName()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest058_getProductComponentName()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest059_setProductComponentName()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest060_getMorphList()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest061_setMorphList()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest062_getUseRelativePaths()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest063_setUseRelativePaths()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest064_isTemporaryFile()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest065_exportAssetWithDTU()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest066_writeJSON_Property_Texture()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest067_makeUniqueFilename()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest068_getUndoNormalMaps()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest069_setUndoNormalMaps()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest070_getNonInteractiveMode()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest071_setNonInteractiveMode()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest072_getExportFbx()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest073_setExportFbx()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest074_readGUI()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest075_exportHD()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest076_upgradeToHD()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest077_WriteWeightMaps()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest078_metaInvokeMethod()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest079_CopyFile()
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest080_GetMD5()
{
	return false;
}


#include "moc_UnitTest_DzBridgeScriptableAction.cpp"
#endif