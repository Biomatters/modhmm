cmake_minimum_required(VERSION 2.4.7)
project(modhmm)

IF(UNIX)	
	IF(CMAKE_COMPILER_IS_GNUCC)
		SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -w")
	ENDIF(CMAKE_COMPILER_IS_GNUCC)
ENDIF(UNIX)
IF(WIN32)

ENDIF(WIN32)

add_subdirectory(src)
