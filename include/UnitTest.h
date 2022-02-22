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

#define DECLARE_TEST(method_name) \
bool method_name(UnitTest::TestResult* testResult);

#define RUNTEST RUNTEST_1ARG

#define RUNTEST_0ARG(method_name) \
createTestResult(#method_name); \
method_name();

#define RUNTEST_1ARG(method_name) \
UnitTest::TestResult *##method_name##_testResult = createTestResult(#method_name); \
method_name(##method_name##_testResult);

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

	UnitTest();

	Q_INVOKABLE bool writeAllTestResults();
	Q_INVOKABLE bool convertTestResutlsToXls();
	Q_INVOKABLE bool convertTestResultsToHtml();
	Q_INVOKABLE QObject* getTestObject();

protected:
	struct TestResult {
		int id;
		QString name;
		QStringList* log;
		bool result;
	};

	UnitTest::TestResult* createTestResult(QString methodName);
	bool logToTestResult(UnitTest::TestResult *testResult, QString text);

	QObject* m_testObject;

private:
	QList<TestResult*> m_testResultList;

};

#endif