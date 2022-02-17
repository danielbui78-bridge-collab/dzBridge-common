#ifdef UNITTEST_DZBRIDGE

#include "UnitTest_DzBridgeSubdivisionDialog.h"
#include "DzBridgeSubdivisionDialog.h"


bool UnitTest_DzBridgeSubdivisionDialog::runUnitTests()
{
	DzBridgeSubdivisionDialog* testObject = new DzBridgeSubdivisionDialog();

	if (!testObject)
	{
		return false;
	}

	return true;
}

#include "moc_UnitTest_DzBridgeSubdivisionDialog.cpp"

#endif