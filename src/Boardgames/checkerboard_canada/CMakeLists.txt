cmake_minimum_required (VERSION 3.3 FATAL_ERROR)

project (Checkerboard_Canada
    VERSION 00.01.00.00
    LANGUAGES CXX C)

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
	src/checker_canada.h
	src/checker_canada.cpp
	)
source_group("" FILES ${SRC})
	
# Creating target
add_library(${PROJECT_NAME} 
  SHARED 
  ${SRC}
)

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "d")

# Add linked libraries by configuration
#target_link_libraries( ${PROJECT_NAME} debug Libreriad optimized Libraria)

