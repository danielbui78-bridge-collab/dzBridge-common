set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(COMMON_LIB_INCLUDE_DIR ${COMMON_LIB_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
set(COMMON_LIB_INCLUDE_DIR ${COMMON_LIB_INCLUDE_DIR} PARENT_SCOPE)

include_directories(${COMMON_LIB_INCLUDE_DIR})
set(LIB_SRCS
	../include/DzRuntimePluginAction.h
	../include/DzBridgeMorphSelectionDialog.h
	../include/DzBridgeSubdivisionDialog.h
	../include/DzBridgeDialog.h
	../include/common_version.h
)
set(LIB_SRCS ${LIB_SRCS} PARENT_SCOPE)