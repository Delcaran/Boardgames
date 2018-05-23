cmake_minimum_required (VERSION 3.3 FATAL_ERROR)

project (Grid 
    VERSION 00.01.00.00
    LANGUAGES CXX C)

# Additional include directories
#include_directories()

# Additional libraries include directories
#link_directories()

# Setting source groups
set( SRC 
	src/Cell.h
	src/common.h
	src/Coordinates.h
	src/Grid.h)
source_group("" FILES ${SRC})
	
# Creating target
add_library(${PROJECT_NAME} 
  SHARED 
  ${SRC}
)

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "d")

# Add linked libraries by configuration
target_link_libraries( ${PROJECT_NAME} debug Libreriad optimized Libraria)

