	#foreach(FILE ${TEST_SRC_FILES})
	#	get_filename_component(TestName "${FILE}" NAME_WE)
	#	
	#	get_filename_component(TestDir  "${FILE}" DIRECTORY)
	#	file(RELATIVE_PATH TestDir ${CMAKE_SOURCE_DIR} ${TestDir})
	#	
	#	string(REGEX REPLACE "[./:]" "_" TestDir ${TestDir})
	#	set(TestName ${TestDir}+${TestName})
	#	
	#	add_executable(${TestName} ${FILE})
	#	target_link_libraries(${TestName} ${GTEST_BOTH_LIBRARIES} Threads::Threads ${TEST_PROJ_DEP} ${GMOCK_LIBS} mock_hardware_low_level)
	#	add_test(NAME ${TestName} COMMAND ${TestName})
    #
	#	#add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND}	DEPENDS ${NAME})
	#endforeach()

function(MakeSingleFileAsSingleTest TestSourcePath TestLib AdditionalLibs TestProjectPrefix)
	if (WIN32)
		set(GTEST_ROOT "C:/Program Files (x86)/googletest-distribution")
		
		set(GMOCK_INCLUDE_DIRS "C:/Program Files (x86)/googletest-distribution/include")
		set(GMOCK_LIBS "C:/Program Files (x86)/googletest-distribution/lib/gmock.lib")
	elseif (UNIX)
		set(GMOCK_LIBS "gmock")
	endif()


	find_package(GTest 		REQUIRED)
	find_package(Threads 	REQUIRED)

	include_directories(${GTEST_INCLUDE_DIRS})
	include_directories(${GMOCK_INCLUDE_DIRS})

	#include testable library source directory:
	get_property(TestLibSourceDir TARGET ${TestLib} PROPERTY SOURCE_DIR)
	include_directories(${TestLibSourceDir})
	

	aux_source_directory(${TestSourcePath} TestSources)
	
	foreach(TestSourceFile ${TestSources})
		get_filename_component(TestName "${TestSourceFile}" NAME_WE)
		
		#get_filename_component(TestDir  "${TestSourceFile}" DIRECTORY)
		#file(RELATIVE_PATH TestDir ${CMAKE_SOURCE_DIR} ${TestDir})
		
		#string(REGEX REPLACE "[./:]" "_" TestDir ${TestDir})
		#set(TestName ${TestDir}+${TestName})
		
		set(TestName ${TestProjectPrefix}_${TestName})
		
		if(BUILD_TEST_WITH_ALL)
			add_executable(${TestName} ${TestSourceFile})
		else()
			add_executable(${TestName} EXCLUDE_FROM_ALL ${TestSourceFile})
		endif()

		target_link_libraries(${TestName} ${GTEST_BOTH_LIBRARIES} ${GMOCK_LIBS} ${TestLib} ${AdditionalLibs} Threads::Threads)
		add_test(NAME ${TestName} COMMAND ${TestName})

		#if (RUN_TEST_AFTER_BUILD)
		#	add_custom_command(TARGET ${TestName} COMMENT "Run tests" POST_BUILD WORKING_DIRECTORY ${CMAKE_BINARY_DIR} COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> -R ${TestName} --output-on-failures)
		#endif()
	endforeach()
endfunction()