cmake_minimum_required (VERSION 3.3 FATAL_ERROR)

set(PRJ_NAME Sbregacamesa)

# Additional include directories
include_directories(
	${CARD_INCLUDE}
	${DECK_INCLUDE}
	)

# Additional libraries include directories
link_directories(${TABLETOP_OUT_DIR})

# Setting source groups
set( SRC
	src/sbregacamesa.h
	src/sbregacamesa.cpp
	)
source_group("" FILES ${SRC})

# Creating target
add_definitions(-D${PRJ_NAME}_EXPORTS) # exporting dll
add_library(${PRJ_NAME}
  SHARED
  ${SRC}
)
add_dependencies(${PRJ_NAME} Deck)

set_target_properties(${PRJ_NAME}  PROPERTIES DEBUG_POSTFIX "d")

# Add linked libraries by configuration
target_link_libraries( ${PRJ_NAME} debug Deckd optimized Deck )
target_link_libraries( ${PRJ_NAME} debug Cardd optimized Card )

# TEST CONFIGURATION
#====================

# Additional include directories
include_directories(
	${CARD_INCLUDE}
	${DECK_INCLUDE}
	src
	)

# Additional libraries include directories
link_directories(${TABLETOP_OUT_DIR})

# Setting source groups
set( SRC test/test.cpp )
source_group("" FILES ${SRC})

# Creating target
add_executable(Sbregacamesa_test ${SRC} )
add_dependencies(Sbregacamesa_test ${PRJ_NAME})

set_target_properties(Sbregacamesa_test  PROPERTIES DEBUG_POSTFIX "d")

# Add linked libraries by configuration
target_link_libraries( Sbregacamesa_test debug Deckd optimized Deck )
target_link_libraries( Sbregacamesa_test debug Cardd optimized Card )
target_link_libraries( Sbregacamesa_test debug Sbregacamesad optimized Sbregacamesa )