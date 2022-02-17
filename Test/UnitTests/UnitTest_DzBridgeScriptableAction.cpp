#ifdef UNITTEST_DZBRIDGE

#include "UnitTest_DzBridgeScriptableAction.h"
#include "DzBridgeScriptableAction.h"


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