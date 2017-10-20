cmake_minimum_required(VERSION 3.1)

if (BUILD_TESTING)
	set(TestedProject ${PROJECT_NAME})
	
	PROJECT(${PROJECT_NAME}_TEST)

		configure_file(etalon_path ${CMAKE_CURRENT_SOURCE_DIR}/etalon_path.h ESCAPE_QUOTES)
	
		include(TestController)
		MakeSingleFileAsSingleTest(${PROJECT_SOURCE_DIR} ${TestedProject} "" ${PROJECT_NAME})
endif(BUILD_TESTING)
