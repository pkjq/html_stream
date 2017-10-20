macro(CollectSourcesInSubdirectories Dir SourcesList HeadersList)
	aux_source_directory(${Dir} DirSources)
	list(APPEND ${SourcesList} ${DirSources})
	
	file(GLOB DirHeaders ${Dir}/*.h ${Dir}/*.hpp)
	list(APPEND ${HeadersList} ${DirHeaders})

	
	file(GLOB SubDirs LIST_DIRECTORIES true ${Dir}/*)

	foreach(DIR ${SubDirs})
		if (IS_DIRECTORY ${DIR})
			#message(STATUS ">>DBG: " "ScanSubDir: " ${DIR} " | O=" ${Dir})
		
			CollectSourcesInSubdirectories(${DIR} ${SourcesList} ${HeadersList})
		endif()
	endforeach()
endmacro()


macro(CollectHeadersInSubdirectories Dir HeadersList)
	file(GLOB_RECURSE 	DirHeaders 	${Dir}/*.h ${Dir}/*.hpp)
	list(APPEND ${HeadersList} ${DirHeaders})
endmacro()


#===================================================================================


function(CollectDirectoriesIfFileExist Dir CollectedDirs FileMustExist)
	file(GLOB SubDirs LIST_DIRECTORIES true ${Dir}/*)

	set(TmpCollectedDirs)
	foreach(SubDir ${SubDirs})
		if (IS_DIRECTORY ${SubDir})
			if (EXISTS ${SubDir}/${FileMustExist})
				list(APPEND TmpCollectedDirs ${SubDir})
			endif()
		endif()
	endforeach()
	
	set(${CollectedDirs} ${TmpCollectedDirs} PARENT_SCOPE)
endfunction()

macro(CollectDirectoriesIfMakeFileExist Dir CollectedDirs)
	CollectDirectoriesIfFileExist(${Dir} ${CollectedDirs} "CMakeLists.txt")
endmacro()

function(AddSubDirectoryIfMakeFileExist Dir)
	CollectDirectoriesIfMakeFileExist(${Dir} SubDirs)
	
	foreach(SubDir ${SubDirs})
		#message(STATUS "DBG4: Adding sub directory: " ${SubDir})
		add_subdirectory(${SubDir})
	endforeach()
endfunction()