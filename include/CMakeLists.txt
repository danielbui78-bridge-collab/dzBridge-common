set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(COMMON_LIB_INCLUDE_DIR ${COMMON_LIB_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
set(COMMON_LIB_INCLUDE_DIR ${COMMON_LIB_INCLUDE_DIR} PARENT_SCOPE)

include_directories(${COMMON_LIB_INCLUDE_DIR})
set(LIB_SRCS
	${LIB_SRCS}
	DzRuntimePluginAction.h
	DzBridgeMorphSelectionDialog.h
	DzBridgeSubdivisionDialog.h
	DzBridgeDialog.h
	common_version.h
)
