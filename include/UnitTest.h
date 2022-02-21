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

#define RUNTEST(unittest_method) \
createTestResult(#unittest_method); \
unittest_method();

class QStringList;

class DLLExport UnitTest : public QObject {
	Q_OBJECT
public:
	Q_INVOKABLE virtual bool runUnitTests()=0;

	Q_INVOKABLE bool writeAllTestResults();
	Q_INVOKABLE bool convertTestResutlsToXls();
	Q_INVOKABLE bool convertTestResultsToHtml();

protected:
	class TestResult {
		int id;
		QString name;
		QStringList* log;
		bool result;
	};

	UnitTest::TestResult* createTestResult(QString name);

private:
	QList<TestResult*> m_testResultList;

};

#endif