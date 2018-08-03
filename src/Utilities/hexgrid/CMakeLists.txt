cmake_minimum_required (VERSION 3.3 FATAL_ERROR)

set(PRJ_NAME HexGrid)

# Additional include directories
include_directories(${GRID_INCLUDE})

# Setting source groups
set( SRC 
	src/hex_grid.h
	src/hex_grid.cpp
	)
source_group("" FILES ${SRC})
	
# Creating target
add_library(${PRJ_NAME} 
  SHARED 
  ${SRC}
)
add_dependencies(${PRJ_NAME} Grid)

set_target_properties(${PRJ_NAME}  PROPERTIES DEBUG_POSTFIX "d")
