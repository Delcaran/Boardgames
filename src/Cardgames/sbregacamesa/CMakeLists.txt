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
add_library(${PRJ_NAME}
  SHARED
  ${SRC}
)

set_target_properties(${PRJ_NAME}  PROPERTIES DEBUG_POSTFIX "d")

# Add linked libraries by configuration
target_link_libraries( ${PRJ_NAME} debug Deckd optimized Deck )
target_link_libraries( ${PRJ_NAME} debug Cardd optimized Card )

