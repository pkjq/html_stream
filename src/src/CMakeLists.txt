set(ProjectSourcesDir 			${CMAKE_CURRENT_SOURCE_DIR})


set(ProjectIfaceLib 			${PROJECT_NAME}_iface)
#set(ProjectPublicMockLib		mock_${PROJECT_NAME})


PROJECT(${PROJECT_NAME})
	set(ProjectOutputName ${PROJECT_NAME})


	include(SourceCollector)
	CollectSourcesInSubdirectories(${ProjectSourcesDir} 				ProjectSources ProjectSourcesHeaders)


	add_library(${ProjectOutputName} 		${ProjectSources} ${ProjectSourcesHeaders})
	include(FixLibrary)
	FixLibrary(${ProjectOutputName})


	set(ProjectAllSources 					${ProjectSources} ${ProjectSourcesHeaders})
	set(ProjectPrivateMockSources 			${ProjectAllSources})

	list(FILTER ProjectAllSources 			EXCLUDE REGEX ".*mock.*")
	list(FILTER ProjectPrivateMockSources 	INCLUDE REGEX ".*mock.*")

	# ==== Grouping ====
	## Sources
	source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "Sources" FILES ${ProjectAllSources})

	## Ifaces
	get_property(ProjectIfaceSources 			TARGET ${ProjectIfaceLib} 			PROPERTY INTERFACE_SOURCES)
	get_property(ProjectIfaceIcludeDir 			TARGET ${ProjectIfaceLib} 			PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
	source_group(TREE ${ProjectIfaceIcludeDir} PREFIX "Iface" FILES ${ProjectIfaceSources})
	
	## Mocks
	#get_property(ProjectPublicMockSources 		TARGET ${ProjectPublicMockLib} 		PROPERTY INTERFACE_SOURCES)
	#get_property(ProjectPublicMockIcludeDir 	TARGET ${ProjectPublicMockLib} 		PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
	#source_group(TREE ${ProjectPublicMockIcludeDir} PREFIX "Mocks" FILES ${ProjectPublicMockSources})
	# =================

	# Link target
	target_link_libraries(${ProjectOutputName}
		PUBLIC  ${ProjectIfaceLib}
#		PRIVATE ${ProjectPublicMockLib}
	)
