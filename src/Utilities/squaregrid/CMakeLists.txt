cmake_minimum_required (VERSION 3.3 FATAL_ERROR)

set(PRJ_NAME SquareGrid)

# Additional include directories
include_directories(${GRID_INCLUDE})

# Setting source groups
set( SRC 
	src/square_grid.h
	src/square_grid.cpp
	)
source_group("" FILES ${SRC})
	
# Creating target
add_library(${PRJ_NAME} 
  SHARED 
  ${SRC}
)

set_target_properties(${PRJ_NAME}  PROPERTIES DEBUG_POSTFIX "d")

