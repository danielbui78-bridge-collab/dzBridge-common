#pragma once

#ifdef UNITTEST_DZBRIDGE

#include <QObject>

#undef DLLExport
#define DLLExport Q_DECL_IMPORT
#ifdef DZ_BRIDGE_SHARED
	#undef DLLExport
	#define DLLExport Q_DECL_EXPORT
#elif DZ_BRIDGE_STATIC
	#undef DLLExport
	#define DLLExport
#endif

class DLLExport UnitTest : public QObject {
	Q_OBJECT
public:
	virtual bool runUnitTests()=0;

};

#endif