cmake_minimum_required (VERSION 3.3 FATAL_ERROR)

set(PRJ_NAME Grid)
# Setting source groups
set( SRC 
	src/Cell.h
	src/Coordinates.h
	src/Grid.h
	)
source_group("" FILES ${SRC})
	
# Creating target
add_library(${PRJ_NAME} 
  STATIC 
  ${SRC}
)

set_target_properties(${PRJ_NAME} 
	PROPERTIES 
	DEBUG_POSTFIX "d" 
	LINKER_LANGUAGE CXX)

