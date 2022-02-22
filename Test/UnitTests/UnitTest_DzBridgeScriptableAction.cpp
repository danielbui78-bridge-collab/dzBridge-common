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
	RUNTEST(unitTest014_exportAsset);
	RUNTEST(unitTest015_exportNode);
	RUNTEST(unitTest016_writeConfiguration);
	RUNTEST(unitTest017_setExportOptions);
	RUNTEST(unitTest018_readGUIRootFolder);
	RUNTEST(unitTest019_writeDTUHeader);
	RUNTEST(unitTest020_startMaterialBlock);
	RUNTEST(unitTest021_finishMaterialBlock);
	RUNTEST(unitTest022_writeMaterialProperty);
	RUNTEST(unitTest023_writeAllMorphs);
	RUNTEST(unitTest024_writeMorphProperties);
	RUNTEST(unitTest025_writeMorphJointLinkInfo);
	RUNTEST(unitTest026_writeAllSubdivisions);
	RUNTEST(unitTest081_writeSubdivisionProperties);
	RUNTEST(unitTest027_writeAllDforceInfo);
	RUNTEST(unitTest028_writeDforceMaterialProperties);
	RUNTEST(unitTest029_writeDforceModifiers);
	RUNTEST(unitTest030_writeEnvironment);
	RUNTEST(unitTest031_writeInstances);
	RUNTEST(unitTest032_writeInstance);
	RUNTEST(unitTest033_writeAllPoses);
	RUNTEST(unitTest034_renameDuplciateMaterials);
	RUNTEST(unitTest035_undoRenameDuplicateMaterials);
	RUNTEST(unitTest036_getScenePropList);
	RUNTEST(unitTest037_disconnectNode);
	RUNTEST(unitTest038_reconnectNodes);
	RUNTEST(unitTest039_disconnectOverrideControllers);
	RUNTEST(unitTest040_reconnectOverrideControllers);
	RUNTEST(unitTest041_checkIfPoseExportIsDestructive);
	RUNTEST(unitTest042_unlockTransform);
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
	bool bResult = true;
	LOGTEST_TEXT("DzBridgeAction is an abstract class.  Can not test constructor.");

/**
	// Can not build because constructor for abstract class
	DzBridgeAction *testObj = new DzBridgeAction();
	if (!testObj)
		LOGTEST_FAILED("");
	else
		LOGTEST_PASSED("");
*/

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest002_resetToDefaults(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->resetToDefaults());

	return true;
}

bool UnitTest_DzBridgeScriptableAction::unitTest003_cleanString(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->cleanString(nullptr));

	TRY_METHODCALL_CUSTOM(qobject_cast<DzBridgeAction*>(m_testObject)->cleanString(""), "C++ exception with empty string test.");

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest004_getAvailableMorphs(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->getAvailableMorphs(new DzNode()));

	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->getAvailableMorphs(nullptr));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest005_getActiveMorphs(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->getActiveMorphs(new DzNode()));

	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->getActiveMorphs(nullptr));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest006_makeNormalMapFromHeightMap(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->makeNormalMapFromHeightMap(nullptr, 0.0));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest007_preProcessScene(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->preProcessScene(new DzNode()));

	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->preProcessScene(nullptr));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest008_renameDuplicateMaterial(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->renameDuplicateMaterial(nullptr, nullptr));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest009_undoRenameDuplicateMaterials(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->undoRenameDuplicateMaterials());

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest010_generateMissingNormalMap(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->generateMissingNormalMap(nullptr));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest011_undoGenerateMissingNormalMaps(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->undoGenerateMissingNormalMaps());

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest012_getActionGroup(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->getActionGroup());

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest013_getDefaultMenuPath(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->getDefaultMenuPath());

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest014_exportAsset(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->exportAsset());

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest015_exportNode(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->exportNode(new DzNode()));

	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->exportNode(nullptr));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest016_writeConfiguration(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->writeConfiguration());

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest017_setExportOptions(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	DzFileIOSettings arg;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->setExportOptions(arg));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest018_readGUIRootFolder(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->readGUIRootFolder());

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest019_writeDTUHeader(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	DzJsonWriter arg(nullptr);
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->writeDTUHeader(arg));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest020_startMaterialBlock(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	DzJsonWriter arg(nullptr);
	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->startMaterialBlock(nullptr, arg, nullptr, nullptr));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest021_finishMaterialBlock(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	DzJsonWriter arg(nullptr);
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->finishMaterialBlock(arg));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest022_writeMaterialProperty(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	DzJsonWriter arg(nullptr);
	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->writeMaterialProperty(nullptr, arg, nullptr, nullptr, nullptr));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest023_writeAllMorphs(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	DzJsonWriter arg(nullptr);
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->writeAllMorphs(arg));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest024_writeMorphProperties(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	DzJsonWriter arg(nullptr);
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->writeMorphProperties(arg, "", ""));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest025_writeMorphJointLinkInfo(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	DzJsonWriter arg1(nullptr);
	JointLinkInfo arg2;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->writeMorphJointLinkInfo(arg1, arg2));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest026_writeAllSubdivisions(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	DzJsonWriter arg(nullptr);
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->writeAllSubdivisions(arg));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest081_writeSubdivisionProperties(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	DzJsonWriter arg(nullptr);
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->writeSubdivisionProperties(arg, "", 0));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest027_writeAllDforceInfo(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	DzJsonWriter arg(nullptr);
	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->writeAllDforceInfo(nullptr, arg));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest028_writeDforceMaterialProperties(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	DzJsonWriter arg(nullptr);
	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->writeDforceMaterialProperties(arg, nullptr, nullptr));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest029_writeDforceModifiers(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	DzJsonWriter arg1(nullptr);
	DzModifierList arg2;
	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->writeDforceModifiers(arg2, arg1, nullptr));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest030_writeEnvironment(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	DzJsonWriter arg(nullptr);
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->writeEnvironment(arg));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest031_writeInstances(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	DzJsonWriter arg1(nullptr);
	QMap<QString, DzMatrix3> arg2;
	QList<DzGeometry*> arg3;
	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->writeInstances(nullptr, arg1, arg2, arg3));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest032_writeInstance(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	DzJsonWriter arg(nullptr);
	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->writeInstance(nullptr, arg, 0));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest033_writeAllPoses(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	DzJsonWriter arg(nullptr);
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->writeAllPoses(arg));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest034_renameDuplciateMaterials(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	QList<QString> arg1;
	QMap<DzMaterial*, QString> arg2;
	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->renameDuplicateMaterials(nullptr, arg1, arg2));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest035_undoRenameDuplicateMaterials(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	QList<QString> arg1;
	QMap<DzMaterial*, QString> arg2;
	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->undoRenameDuplicateMaterials(nullptr, arg1, arg2));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest036_getScenePropList(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	QMap<QString, DzNode*> arg;
	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->getScenePropList(nullptr, arg));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest037_disconnectNode(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	QList<DzBridgeAction::AttachmentInfo> arg;
	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->disconnectNode(nullptr, arg));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest038_reconnectNodes(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	QList<DzBridgeAction::AttachmentInfo> arg;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->reconnectNodes(arg));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest039_disconnectOverrideControllers(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->disconnectOverrideControllers());

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest040_reconnectOverrideControllers(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	QList<QString> arg;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->reconnectOverrideControllers(arg));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest041_checkIfPoseExportIsDestructive(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->checkIfPoseExportIsDestructive());

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest042_unlockTransform(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->unlockTranform(nullptr));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest043_getBridgeDialog(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->getBridgeDialog());

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest044_setBridgeDialog(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->setBridgeDialog(nullptr));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest045_getSubdivisionDialog(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->getSubdivisionDialog());

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest046_setSubdivisionDialog(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->setSubdivisionDialog(nullptr));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest047_getMorphSelectionDialog(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->getMorphSelectionDialog());

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest082_getMorphSelectionDialog(UnitTest::TestResult* testResult)
{
	return false;
}

bool UnitTest_DzBridgeScriptableAction::unitTest048_getAssetType(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->getAssetType());

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest049_setAssetType(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->setAssetType(""));

	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->setAssetType(nullptr));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest050_getExportFilename(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->getExportFilename());

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest051_setExportFilename(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->setExportFilename(""));

	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->setExportFilename(nullptr));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest052_getExportFolder(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->getExportFolder());

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest053_setExportFolder(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->setExportFolder(""));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest054_getRootFolder(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->getRootFolder());

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest055_setRootFolder(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->setRootFolder(""));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest056_getProductName(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->getProductName());

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest057_setProductName(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->setProductName(""));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest058_getProductComponentName(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->getProductComponentName());

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest059_setProductComponentName(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->setProductComponentName(""));

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest060_getMorphList(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->getMorphList());

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest061_setMorphList(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	QStringList arg;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->setMorphList(arg));

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest062_getUseRelativePaths(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->getUseRelativePaths());

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest063_setUseRelativePaths(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->setUseRelativePaths(0));

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest064_isTemporaryFile(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->isTemporaryFile(""));

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest065_exportAssetWithDTU(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->exportAssetWithDtu(""));

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest066_writeJSON_Property_Texture(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	DzJsonWriter arg(nullptr);
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->writePropertyTexture(arg,"",0,"",""));

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest067_makeUniqueFilename(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->makeUniqueFilename(""));

	return bResult;
}

bool UnitTest_DzBridgeScriptableAction::unitTest068_getUndoNormalMaps(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->getUndoNormalMaps());

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest069_setUndoNormalMaps(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->setUndoNormalMaps(0));

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest070_getNonInteractiveMode(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->getNonInteractiveMode());

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest071_setNonInteractiveMode(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->setNonInteractiveMode(0));

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest072_getExportFbx(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->getExportFbx());

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest073_setExportFbx(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->setExportFbx(""));

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest074_readGUI(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->readGui(nullptr));

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest075_exportHD(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->exportHD());

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest076_upgradeToHD(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->upgradeToHD("","", "", nullptr));

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest077_WriteWeightMaps(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	DzJsonWriter arg(nullptr);
	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->writeWeightMaps(nullptr, arg));

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest078_metaInvokeMethod(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->metaInvokeMethod(nullptr, nullptr, nullptr));

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest079_CopyFile(UnitTest::TestResult* testResult)
{
	bool bResult = false;
	LOGTEST_FAILED("CopyFile won't build");
//	TRY_METHODCALL_NULLPTR(qobject_cast<DzBridgeAction*>(m_testObject)->CopyFile(nullptr, nullptr));

	return bResult;

}

bool UnitTest_DzBridgeScriptableAction::unitTest080_GetMD5(UnitTest::TestResult* testResult)
{
	bool bResult = true;
	TRY_METHODCALL(qobject_cast<DzBridgeAction*>(m_testObject)->GetMD5(""));

	return bResult;

}




#include "moc_UnitTest_DzBridgeScriptableAction.cpp"
#endif