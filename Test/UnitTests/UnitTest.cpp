#ifdef UNITTEST_DZBRIDGE

#include "UnitTest.h"
#include <qstringlist.h>

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

UnitTest::TestResult* UnitTest::createTestResult(QString methodName)
{
    UnitTest::TestResult* test = new UnitTest::TestResult();
    test->id = m_testResultList.count();
    test->name = methodName;
    test->log = new QStringList();
    test->result = false;

    m_testResultList.append(test);

    return test;
}

bool UnitTest::logToTestResult(UnitTest::TestResult* testResult, QString text)
{
    if (!testResult || !testResult->log)
        return false;

    testResult->log->append(text);

    return true;
}



#endif