cmake_minimum_required (VERSION 3.3 FATAL_ERROR)

set(PRJ_NAME Card)

# Setting source groups
set( SRC
	src/card.h
	src/card.cpp
	)
source_group("" FILES ${SRC})

# Creating target
add_definitions(-D${PRJ_NAME}_EXPORTS) # exporting dll
add_library(${PRJ_NAME}
  SHARED
  ${SRC}
)

set_target_properties(${PRJ_NAME}  PROPERTIES DEBUG_POSTFIX "d")

