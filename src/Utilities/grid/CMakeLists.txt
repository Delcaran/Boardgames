cmake_minimum_required (VERSION 3.3 FATAL_ERROR)

set(PRJ_NAME Grid)

# Additional include directories
#include_directories(${GRID_INCLUDE})

# Additional libraries include directories
#link_directories(${BOARDGAMES_OUT_DIR})

# Setting source groups
set( SRC 
	src/Cell.h
	src/common.h
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

# Add linked libraries by configuration
#target_link_libraries( ${PRJ_NAME} debug Libreriad optimized Libraria)

