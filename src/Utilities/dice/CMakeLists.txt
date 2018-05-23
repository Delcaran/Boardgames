cmake_minimum_required (VERSION 3.3 FATAL_ERROR)

set(PRJ_NAME Dice)

# Setting source groups
set( SRC 
	src/dice.h
	src/dice.cpp
	)
source_group("" FILES ${SRC})
	
# Creating target
add_library(${PRJ_NAME} 
  SHARED 
  ${SRC}
)

set_target_properties(${PRJ_NAME}  PROPERTIES DEBUG_POSTFIX "d")

