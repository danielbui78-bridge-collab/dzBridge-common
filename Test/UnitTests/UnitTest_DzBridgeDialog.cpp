#ifdef UNITTEST_DZBRIDGE

#include "UnitTest_DzBridgeDialog.h"
#include "DzBridgeDialog.h"


bool UnitTest_DzBridgeDialog::runUnitTests()
{
	DzBridgeDialog* testObject = new DzBridgeDialog();

	if (!testObject)
	{
		return false;
	}

	return true;
}

#include "moc_UnitTest_DzBridgeDialog.cpp"

#endif