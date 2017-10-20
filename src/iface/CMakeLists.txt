PROJECT(${PROJECT_NAME}_iface)
	set(ProjectOutputName 					${PROJECT_NAME})

	set(ProjectPublicHeadersDir				${CMAKE_CURRENT_SOURCE_DIR})



	include(SourceCollector)
	CollectHeadersInSubdirectories(${ProjectPublicHeadersDir} 			ProjectPublicHeaders)


	add_library(${ProjectOutputName} 	INTERFACE)


	target_sources(${ProjectOutputName} 			INTERFACE ${ProjectPublicHeaders})
	target_include_directories(${ProjectOutputName} INTERFACE ${ProjectPublicHeadersDir})

	target_link_libraries(${ProjectOutputName} INTERFACE)
