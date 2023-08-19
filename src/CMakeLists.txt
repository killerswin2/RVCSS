cmake_minimum_required (VERSION 3.0)


file(GLOB COMMAND_SOURCES commands/*.hpp commands/*.cpp)

file(GLOB CSHARP_SOURCES CSharp/*.hpp CSharp/*.cpp)

file(GLOB_RECURSE HOSTING_SOURCES hosting/*.hpp hosting/*.cpp hosting/*.h)

file(GLOB TEST_SOURCES Tests/*.hpp Tests/*.cpp)

file(GLOB_RECURSE WRAPPER_SOURCES wrappers/*.hpp wrappers/*.cpp)

set(INTERCEPT_PLUGIN_SOURCES main.cpp ${WRAPPER_SOURCES} ${HOSTING_SOURCES} ${CSHARP_SOURCES} ${COMMAND_SOURCES})
SOURCE_GROUP("src" FILES ${INTERCEPT_PLUGIN_SOURCES})


#If you want to split your source files into different directories you can do so here

#The SOURCE_GROUP string is the directory it will display as inside your visual studio.
#Here is a example of a "utilities" subdirectory.

#file(GLOB INTERCEPT_plugin_utilities_SOURCES "utilities/*.cpp" "utilities/*.hpp" "utilities/*.h")
#SOURCE_GROUP("src/utilities" FILES ${INTERCEPT_plugin_utilities_SOURCES})

#----Don't change anything below this line


#include the Intercept headers from the submodule
set(INTERCEPT_CLIENT_PATH "${CMAKE_SOURCE_DIR}/intercept/src/client")
set(INTERCEPT_HOST_PATH "${CMAKE_SOURCE_DIR}/intercept/src/host")

set(INTERCEPT_INCLUDE_PATH "${INTERCEPT_CLIENT_PATH}/headers" "${INTERCEPT_CLIENT_PATH}/headers/shared" "${INTERCEPT_CLIENT_PATH}/headers/client/" "${INTERCEPT_CLIENT_PATH}/headers/client/sqf")


if(USE_64BIT_BUILD)
    set(INTERCEPT_PLUGIN_NAME "${CMAKE_PROJECT_NAME}_x64")
	set(INTERCEPT_EXTENSION_NAME "intercept_x64")
else()
    set(INTERCEPT_PLUGIN_NAME "${CMAKE_PROJECT_NAME}")
	set(INTERCEPT_EXTENSION_NAME "intercept")
endif()

add_definitions(/DINTERCEPT_NO_THREAD_SAFETY)

if(USE_ENGINE_TYPES)
    add_definitions(/DINTERCEPT_SQF_STRTYPE_RSTRING)
endif()

file(GLOB INTERCEPT_CLIENT_SOURCES "${INTERCEPT_CLIENT_PATH}/intercept/client/*.cpp"  "${INTERCEPT_CLIENT_PATH}/intercept/client/sqf/*.cpp" "${INTERCEPT_CLIENT_PATH}/intercept/shared/*.cpp")
SOURCE_GROUP("intercept" FILES ${INTERCEPT_CLIENT_SOURCES})

add_library( ${INTERCEPT_PLUGIN_NAME} SHARED ${INTERCEPT_PLUGIN_SOURCES} ${INTERCEPT_CLIENT_SOURCES} )

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${INTERCEPT_INCLUDE_PATH})

set_target_properties(${INTERCEPT_PLUGIN_NAME} PROPERTIES PREFIX "")
set_target_properties(${INTERCEPT_PLUGIN_NAME} PROPERTIES FOLDER "${CMAKE_PROJECT_NAME}")

if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "-std=c++1z -O2 -s -fPIC -fpermissive -static-libgcc -static-libstdc++")#-march=i686 -m32
	set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
	set(CMAKE_SHARED_LINKER_FLAGS "-shared -static-libgcc -static-libstdc++")
else()
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /std:c++latest" )
	set(CMAKE_CXX_FLAGS_DEBUG "/D_DEBUG /MTd /Zi /Ob0 /Od /RTC1 /MP /EHsc")
	set(CMAKE_CXX_FLAGS_RELEASE "/MT /Zi /O2 /Ob1 /EHsc /MP") #with debug info
	set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "/OPT:REF /DEBUG:FULL") 
endif()
#find_library(INTERCEPT_LIBARAY_STATIC NAMES ${INTERCEPT_EXTENSION_NAME}_static HINTS "${CMAKE_BINARY_DIR}/intercept/src/host/intercept_dll")
#message(${INTERCEPT_LIBARAY_STATIC})

if(APPLE)
    set(DOTNET_RUNTIME_VERSION "7.0.3")
    set(DOTNET_SDK_VERSION "7.0.201")
    set(DOTNET_SDK_ROOT_PATH "/usr/local/share/dotnet")
    set(DOTNET_SDK_PATH "${DOTNET_SDK_ROOT_PATH}/sdk/${DOTNET_SDK_VERSION}")
    set(DOTNET_SDK_RUNTIME_PATH "${DOTNET_SDK_ROOT_PATH}/shared/Microsoft.NETCore.App/${DOTNET_RUNTIME_VERSION}")
    set(DOTNET_SDK_NETHOST_PATH "${DOTNET_SDK_ROOT_PATH}/packs/Microsoft.NETCore.App.Host.osx-arm64/${DOTNET_RUNTIME_VERSION}/runtimes/osx-arm64/native")
    set(DOTNET_SDK_FXRHOST_PATH "${DOTNET_SDK_ROOT_PATH}/host/fxr/${DOTNET_RUNTIME_VERSION}")
endif()

if(WIN32)
    set(DOTNET_RUNTIME_VERSION "7.0.5")
    set(DOTNET_SDK_VERSION "7.0.203")
    set(DOTNET_SDK_ROOT_PATH "C:/Program Files/dotnet")
    set(DOTNET_SDK_PATH "${DOTNET_SDK_ROOT_PATH}/sdk/${DOTNET_SDK_VERSION}")
    set(DOTNET_SDK_RUNTIME_PATH "${DOTNET_SDK_ROOT_PATH}/shared/Microsoft.NETCore.App/${DOTNET_RUNTIME_VERSION}")
    set(DOTNET_SDK_NETHOST_PATH "${DOTNET_SDK_ROOT_PATH}/packs/Microsoft.NETCore.App.Host.win-x64/${DOTNET_RUNTIME_VERSION}/runtimes/win-x64/native")
    set(DOTNET_SDK_FXRHOST_PATH "${DOTNET_SDK_ROOT_PATH}/host/fxr/${DOTNET_RUNTIME_VERSION}")
endif()

message(${DOTNET_SDK_NETHOST_PATH})
message(${DOTNET_SDK_RUNTIME_PATH})
message(${DOTNET_SDK_PATH})
message(${DOTNET_SDK_ROOT_PATH})
message(${DOTNET_SDK_FXRHOST_PATH})

target_link_directories(${INTERCEPT_PLUGIN_NAME} PUBLIC ${DOTNET_SDK_ROOT_PATH} PUBLIC ${DOTNET_SDK_PATH} PUBLIC ${DOTNET_SDK_RUNTIME_PATH} PUBLIC ${DOTNET_SDK_NETHOST_PATH} PUBLIC ${DOTNET_SDK_FXRHOST_PATH})
target_include_directories(${INTERCEPT_PLUGIN_NAME} PUBLIC ${DOTNET_SDK_ROOT_PATH} PUBLIC ${DOTNET_SDK_PATH} PUBLIC ${DOTNET_SDK_RUNTIME_PATH} PUBLIC ${DOTNET_SDK_NETHOST_PATH})
target_link_libraries(${INTERCEPT_PLUGIN_NAME} PUBLIC $<$<CONFIG:Debug>:nethost> PUBLIC $<$<CONFIG:Release>:libnethost>)
set_property(TARGET ${INTERCEPT_PLUGIN_NAME} PROPERTY
  MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

target_compile_definitions(${INTERCEPT_PLUGIN_NAME} PUBLIC $<$<CONFIG:Release>:NETHOST_USE_AS_STATIC> $<$<CONFIG:DEBUG>:UNIT_TESTING_BUILD>)

find_program(DOTNET NAMES dotnet)
message(${DOTNET})


add_custom_command(TARGET ${INTERCEPT_PLUGIN_NAME} 
				POST_BUILD
				COMMAND ${DOTNET} run --project "${CMAKE_SOURCE_DIR}/tools/PostBuilder" -- "${CMAKE_SOURCE_DIR}/tools/PostBuilder")
