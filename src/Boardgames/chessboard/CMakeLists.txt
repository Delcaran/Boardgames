cmake_minimum_required (VERSION 3.3 FATAL_ERROR)

set(PRJ_NAME Chessboard)

# Additional include directories
include_directories(
	${GRID_INCLUDE}
	${SQUAREGRID_INCLUDE}
	${BOARDGAMES_DIR}/checkerboard/src
	)

# Additional libraries include directories
link_directories(${BOARDGAMES_OUT_DIR})

# Setting source groups
set( SRC 
	src/chessboard.h
	src/chessboard.cpp
	src/pieces.h
	src/pieces.cpp
	)
source_group("" FILES ${SRC})
	
# Creating target
add_library(${PRJ_NAME} 
  SHARED 
  ${SRC}
)

set_target_properties(${PRJ_NAME}  PROPERTIES DEBUG_POSTFIX "d")

# Add linked libraries by configuration
#target_link_libraries( ${PRJ_NAME} debug Libreriad optimized Libraria)

