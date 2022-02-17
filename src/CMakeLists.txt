set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(COMMON_LIB_INCLUDE_DIR ${COMMON_LIB_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
set(COMMON_LIB_INCLUDE_DIR ${COMMON_LIB_INCLUDE_DIR} PARENT_SCOPE)

include_directories(${COMMON_LIB_INCLUDE_DIR})

if(WIN32)
	set(OS_SOURCES
#		DzBridge.def
	)
elseif(APPLE)	
	set(OS_SOURCES "")
endif()

set(OFBXI_SOURCES
	OpenFBXInterface.cpp
	../include/OpenFBXInterface.h
)

set(OSDI_SOURCES
	OpenSubdivInterface.cpp
	../include/OpenSubdivInterface.h
)

set(LIB_SRCS
	${LIB_HEADERS}
	DzRuntimePluginAction.cpp
	DzBridgeMorphSelectionDialog.cpp
	DzBridgeSubdivisionDialog.cpp
	DzBridgeDialog.cpp
	${QA_SRCS}
)

add_library(dzbridge-static 
	STATIC 
	${LIB_SRCS}
)

target_include_directories(dzbridge-static
	PUBLIC 
	${FBX_SDK_INCLUDE}
	${OPENSUBDIV_INCLUDE}
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
	${OS_SOURCES}
	${OFBXI_SOURCES}
	${OSDI_SOURCES}
	pluginmain.cpp
	DzBridgeScriptableAction.h
	DzBridgeScriptableAction.cpp
)

target_include_directories(dzbridge
	PUBLIC 
	${FBX_SDK_INCLUDE}
	${OPENSUBDIV_INCLUDE}
)

target_link_libraries(dzbridge
	PRIVATE 
	dzcore
	${DZSDK_QT_CORE_TARGET}
	${DZSDK_QT_GUI_TARGET}
	${DZSDK_QT_SCRIPT_TARGET}
	${DZSDK_QT_NETWORK_TARGET}
	${FBX_IMPORT_LIBS}
	${OPENSUBDIV_LIB}
)

set_target_properties (dzbridge
	PROPERTIES
	FOLDER ""
	PROJECT_LABEL "DzBridge DLL"
)

target_compile_definitions(dzbridge
	PUBLIC
	DZ_BRIDGE_SHARED
	$<$<CONFIG:DEBUG>:UNITTEST_DZBRIDGE>
)

target_compile_definitions(dzbridge-static
	PUBLIC
	DZ_BRIDGE_STATIC
	$<$<CONFIG:DEBUG>:UNITTEST_DZBRIDGE>
)
