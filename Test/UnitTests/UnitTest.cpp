#ifdef UNITTEST_DZBRIDGE

#include "UnitTest.h"
#include <qstringlist.h>
#include <qfile.h>
#include <dzjsonwriter.h>

// UnitTest does not have any methods

#include "moc_UnitTest.cpp"

UnitTest::UnitTest()
{
    m_testObject = nullptr;
}

bool UnitTest::writeAllTestResults()
{
    QFile textOutput("UnitTest_Results.txt");
    textOutput.open(QIODevice::WriteOnly);
    
    QFile jsonFile("UnitTest_Results.json");
    jsonFile.open(QIODevice::WriteOnly);
    DzJsonWriter writer(&jsonFile);

    // write JSON header
    writer.startObject(true);
    writer.addMember("UnitTest Results Version", 1);
    writer.addMember("Class Name", QString(m_testObject->metaObject()->className()) );
    writer.addMember("Number of UnitTests", m_testResultList.count());

    writer.startMemberArray("Detailed Test Results", true);
    // write detailed unittests output
    QList<TestResult*>::iterator testResult_iter = m_testResultList.begin();
    while (testResult_iter != m_testResultList.end())
    {
        UnitTest::TestResult* testResult = *testResult_iter;
        if (testResult)
        {
            writer.startObject(true);
            writer.addMember("UnitTest ID", testResult->id);
            writer.addMember("Method Name", testResult->name);
            writer.addMember("Test Result", testResult->result);
            if (testResult->log)
            {
                QString testResult_buffer = testResult->log->join("\n");
                // format test result header
                // output buffer
                writer.addMember("Test Log", testResult_buffer);
            }
            writer.finishObject();
        }
        testResult_iter++;
    }
    writer.finishArray();


    // write unittests summary
    testResult_iter = m_testResultList.begin();
    // format summary header
    while (testResult_iter != m_testResultList.end())
    {
        UnitTest::TestResult* testResult = *testResult_iter;
        if (testResult)
        {
            // print test result line
            QString resultString = "[ *** FAILED *** ]";
            if (testResult->result)
                resultString = "[ PASSED ]";
            QString testResult_line = testResult->name + ": " + resultString;
        }
        testResult_iter++;
    }


    writer.finishArray();
    writer.finishObject();
    jsonFile.close();

    textOutput.close();

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

QObject* UnitTest::getTestObject()
{
    return m_testObject;
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