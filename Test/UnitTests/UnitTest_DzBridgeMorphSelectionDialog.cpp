#ifdef UNITTEST_DZBRIDGE

#include "UnitTest_DzBridgeMorphSelectionDialog.h"
#include "DzBridgeMorphSelectionDialog.h"


bool UnitTest_DzBridgeMorphSelectionDialog::runUnitTests()
{
	DzBridgeMorphSelectionDialog* testObject = new DzBridgeMorphSelectionDialog();

	if (!testObject)
	{
		return false;
	}

	return true;
}

#include "moc_UnitTest_DzBridgeMorphSelectionDialog.cpp"

#endif