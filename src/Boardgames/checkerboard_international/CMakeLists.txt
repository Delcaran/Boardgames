cmake_minimum_required (VERSION 3.3 FATAL_ERROR)

set(PRJ_NAME Checkboard_International)

# Additional include directories
include_directories(
	${GRID_INCLUDE}
	${SQUAREGRID_INCLUDE}
	${BOARDGAMES_DIR}/checkerboard/src
	)

# Additional libraries include directories
link_directories(${TABLETOP_OUT_DIR})

# Setting source groups
set( SRC 
	src/checker_international.h
	src/checker_international.cpp
	)
source_group("" FILES ${SRC})
	
# Creating target
add_library(${PRJ_NAME} 
  SHARED 
  ${SRC}
)

set_target_properties(${PRJ_NAME}  PROPERTIES DEBUG_POSTFIX "d")

# Add linked libraries by configuration
target_link_libraries( ${PRJ_NAME} debug SquareGridd optimized SquareGrid )
target_link_libraries( ${PRJ_NAME} debug Checkerboardd optimized Checkerboard )

