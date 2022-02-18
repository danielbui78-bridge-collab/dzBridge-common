#ifdef UNITTEST_DZBRIDGE

#include "UnitTest_DzBridgeScriptableAction.h"
#include "DzBridgeScriptableAction.h"

/// <summary>
/// This class also tests DzBridgeAction indirectly since DzBridgeAction is an abstract base class.
/// </summary>
/// <returns></returns>
bool UnitTest_DzBridgeScriptableAction::runUnitTests()
{
	DzBridgeScriptableAction* testObject = new DzBridgeScriptableAction();

	if (!testObject)
	{
		return false;
	}

	return true;
}


#include "moc_UnitTest_DzBridgeScriptableAction.cpp"

#endif