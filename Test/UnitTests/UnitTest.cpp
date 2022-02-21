#ifdef UNITTEST_DZBRIDGE

#include "UnitTest.h"

// UnitTest does not have any methods

#include "moc_UnitTest.cpp"

bool UnitTest::writeAllTestResults()
{
    return false;
}

bool UnitTest::convertTestResutlsToXls()
{
    return false;
}

bool UnitTest::convertTestResultsToHtml()
{
    return false;
}

UnitTest::TestResult* UnitTest::createTestResult(QString name)
{
    return nullptr;
}



#endif