#pragma once

#ifdef UNITTEST_DZBRIDGE

#include <QObject>
#include <qlist.h>

#undef DLLExport
#define DLLExport Q_DECL_IMPORT
#ifdef DZ_BRIDGE_SHARED
	#undef DLLExport
	#define DLLExport Q_DECL_EXPORT
#elif DZ_BRIDGE_STATIC
	#undef DLLExport
	#define DLLExport
#endif

#define RUNTEST RUNTEST_0ARG

#define RUNTEST_0ARG(unittest_method) \
createTestResult(#unittest_method); \
unittest_method();

#define RUNTEST_1ARG(unittest_method) \
UnitTest::TestResult *unittest_method_testResult = createTestResult(#unittest_method); \
unittest_method(unittest_method_testResult);

#define LOGTEST_TEXT(text) \
logToTestResult(testResult, QString(text));

#define LOGTEST_FAILED(text) \
LOGTEST_TEXT(testResult->name + ": failed. " + text);

#define LOGTEST_PASSED(text) \
LOGTEST_TEXT(testResult->name + ": passed. " + text);

class QStringList;

class DLLExport UnitTest : public QObject {
	Q_OBJECT
public:
	Q_INVOKABLE virtual bool runUnitTests()=0;

	Q_INVOKABLE bool writeAllTestResults();
	Q_INVOKABLE bool convertTestResutlsToXls();
	Q_INVOKABLE bool convertTestResultsToHtml();

protected:
	struct TestResult {
		int id;
		QString name;
		QStringList* log;
		bool result;
	};

	UnitTest::TestResult* createTestResult(QString methodName);
	bool logToTestResult(UnitTest::TestResult *testResult, QString text);

private:
	QList<TestResult*> m_testResultList;

};

#endif