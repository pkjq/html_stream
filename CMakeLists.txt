cmake_minimum_required(VERSION 3.1)


#include(CTest)
set(BUILD_TESTING ON)
option(BUILD_TEST_WITH_ALL 	"build test with target ALL" 			ON)
option(RUN_TEST_AFTER_BUILD "run test after build" 					ON)


if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "In-source builds not allowed." )
endif()


# set output directory for all executable modules
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
#set(BUILD_SHARED_LIBS	ON)


if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE RelWithDbgInfo)
endif()
string(TOLOWER ${CMAKE_BUILD_TYPE} CMAKE_BUILD_TYPE)


#---
#add submodules includes
include_directories(${CMAKE_SOURCE_DIR}/external/ctti/include)
include_directories(${CMAKE_SOURCE_DIR}/external/MyHeaders/include)
#---


if (UNIX)
	include_directories(/usr/local/include)
elseif (WIN32)
	add_definitions(-DGTEST_LANG_CXX11)
endif()

if (BUILD_TESTING)
	enable_testing()
endif()


add_subdirectory(src)
