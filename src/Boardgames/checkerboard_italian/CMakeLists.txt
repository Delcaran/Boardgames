cmake_minimum_required (VERSION 3.3 FATAL_ERROR)

set(PRJ_NAME Checkboard_Italian)

# Additional include directories
include_directories(
	${GRID_INCLUDE}
	${SQUAREGRID_INCLUDE}
	${BOARDGAMES_DIR}/checkerboard/src
	${BOARDGAMES_DIR}/chessboard/src
	)

# Additional libraries include directories
link_directories(${TABLETOP_OUT_DIR})

# Setting source groups
set( SRC 
	src/checker_italy.h
	src/checker_italy.cpp
	)
source_group("" FILES ${SRC})
	
# Creating target
add_library(${PRJ_NAME} 
  SHARED 
  ${SRC}
)
add_dependencies(${PRJ_NAME} Checkerboard Chessboard)

set_target_properties(${PRJ_NAME}  PROPERTIES DEBUG_POSTFIX "d")

# Add linked libraries by configuration
target_link_libraries( ${PRJ_NAME} debug SquareGridd optimized SquareGrid )
target_link_libraries( ${PRJ_NAME} debug Checkerboardd optimized Checkerboard )
target_link_libraries( ${PRJ_NAME} debug Chessboardd optimized Chessboard )

