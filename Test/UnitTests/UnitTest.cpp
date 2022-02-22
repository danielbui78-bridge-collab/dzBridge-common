#ifdef UNITTEST_DZBRIDGE

#include "UnitTest.h"
#include <qstringlist.h>
#include <qfile.h>
#include <dzjsonwriter.h>
#include <dzapp.h>

// UnitTest does not have any methods

#include "moc_UnitTest.cpp"

UnitTest::UnitTest()
{
    m_testObject = nullptr;
}

bool UnitTest::writeAllTestResults(QString outputPath)
{
    if (outputPath == "")
    {
        outputPath = dzApp->getDocumentsPath();
    }
    QString sClassName = m_testObject ? m_testObject->metaObject()->className() : this->metaObject()->className();
    QString sFileNameStem = "TestResults_" + sClassName;

    QFile jsonFile(outputPath + "/" + sFileNameStem + ".json");
    jsonFile.open(QIODevice::WriteOnly);
    DzJsonWriter writer(&jsonFile);
    // write JSON header
    writer.startObject(true);
    writer.addMember("UnitTest Results Version", 1);
    writer.addMember("Class Name", sClassName);
    writer.addMember("Number of UnitTests", m_testResultList.count());
    writer.startMemberArray("Detailed Test Results", true);
    // write detailed unittests output
    for (auto testResult_iter = m_testResultList.begin(); testResult_iter != m_testResultList.end(); testResult_iter++)
    {
        UnitTest::TestResult* testResult = *testResult_iter;
        if (testResult)
        {
            writer.startObject(true);
            writer.addMember("UnitTest ID", testResult->nId);
            writer.addMember("Method Name", testResult->sName);
            writer.addMember("Test Result", testResult->bResult);
            if (testResult->aLog)
            {
                QString testResult_buffer = testResult->aLog->join("\n");
                // format test result header
                // output buffer
                writer.addMember("Test Log", testResult_buffer);
            }
            writer.finishObject();
        }
    }
    writer.finishArray();
    writer.finishArray();
    writer.finishObject();
    jsonFile.close();

    // write unittests summary
    QFile textOutput(outputPath + "/" + sFileNameStem + ".txt");
    textOutput.open(QIODevice::WriteOnly);
    // write summary header
    textOutput.write("======= UnitTest Summary =======\n");
    textOutput.write("\n");
    textOutput.write( QString("Class Name: " + sClassName + "\n").toLocal8Bit() );
    textOutput.write( QString("Number of UnitTests: %1\n").arg(m_testResultList.count()).toLocal8Bit() );
    textOutput.write("\n");
//    textOutput.write("--------------------------------\n");
    // calculate spacing for method name print out
    int nMethodNameSpacing = 0;
    for(auto testResult_iter = m_testResultList.begin(); testResult_iter != m_testResultList.end(); testResult_iter++)
    {
        UnitTest::TestResult* testResult = *testResult_iter;
        if (testResult)
        {
            if (nMethodNameSpacing < testResult->sName.length())
                nMethodNameSpacing = testResult->sName.length();
        }
    }
    // print each unittest result line
    int nUnitTestCount = 1;
    for (auto testResult_iter = m_testResultList.begin(); testResult_iter != m_testResultList.end(); testResult_iter++)
    {
        UnitTest::TestResult* testResult = *testResult_iter;
        if (testResult)
        {
            // print test result line
            QString sResultString = "*** FAILED ***";
            if (testResult->bResult)
                sResultString = "PASSED";
            QString sMethodName = QString(testResult->sName + ":").leftJustified(nMethodNameSpacing+2, '.');
            QString sTestResult_line = QString("[%1] %2[ %3 ]\n").arg(nUnitTestCount++,2).arg(sMethodName).arg(sResultString);
            textOutput.write( sTestResult_line.toLocal8Bit() );
        }
    }
//    textOutput.write("--------------------------------\n");
    textOutput.write("\n");
    textOutput.write("End of Report.\n");
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
    test->nId = m_testResultList.count();
    test->sName = methodName;
    test->aLog = new QStringList();
    test->bResult = false;

    m_testResultList.append(test);

    return test;
}

bool UnitTest::logToTestResult(UnitTest::TestResult* testResult, QString text)
{
    if (!testResult || !testResult->aLog)
        return false;

    testResult->aLog->append(text);

    return true;
}



#endif