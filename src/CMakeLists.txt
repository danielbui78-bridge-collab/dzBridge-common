set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(COMMON_LIB_INCLUDE_DIR ${COMMON_LIB_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
set(COMMON_LIB_INCLUDE_DIR ${COMMON_LIB_INCLUDE_DIR} PARENT_SCOPE)

include_directories(${COMMON_LIB_INCLUDE_DIR})

if(WIN32)
	set(OS_SOURCES
		DzBridge.def
	)
elseif(APPLE)	
	set(OS_SOURCES "")
endif()

set(LIB_SRCS
	${LIB_SRCS}
	DzRuntimePluginAction.cpp
	DzBridgeMorphSelectionDialog.cpp
	DzBridgeSubdivisionDialog.cpp
	DzBridgeDialog.cpp
)

add_library(dzbridge-static 
	STATIC 
	${LIB_SRCS}
)

target_link_libraries(dzbridge-static
	PRIVATE 
	dzcore
	${DZSDK_QT_CORE_TARGET}
	${DZSDK_QT_GUI_TARGET}
	${DZSDK_QT_SCRIPT_TARGET}
	${DZSDK_QT_NETWORK_TARGET}
)

set_target_properties (dzbridge-static
	PROPERTIES
	FOLDER ""
	PROJECT_LABEL "DzBridge Static"
)

add_library(dzbridge
	SHARED 
	${LIB_SRCS}
	pluginmain.cpp
	${OS_SOURCES}
)

target_link_libraries(dzbridge
	PRIVATE 
	dzcore
	${DZSDK_QT_CORE_TARGET}
	${DZSDK_QT_GUI_TARGET}
	${DZSDK_QT_SCRIPT_TARGET}
	${DZSDK_QT_NETWORK_TARGET}
)

set_target_properties (dzbridge
	PROPERTIES
	FOLDER ""
	PROJECT_LABEL "DzBridge DLL"
)
