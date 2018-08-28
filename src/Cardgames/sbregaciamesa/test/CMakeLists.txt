cmake_minimum_required (VERSION 3.3 FATAL_ERROR)

set(PRJ_NAME SbregaciamesaGUI)

# Impostazioni per QT
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)
# Find the QtWidgets library
find_package(Qt5 CONFIG REQUIRED Widgets)
# Fine impostazioni per qt


# Additional include directories
include_directories(
	${CARD_INCLUDE}
	${DECK_INCLUDE}
	../src
    )

# Additional libraries include directories
link_directories(${TABLETOP_OUT_DIR})

# Setting source groups
set( SRC 
     main.cpp
     edge.cpp
     edge.h
     node.cpp
     node.h
     graphwidget.cpp
     graphwidget.h
     )
source_group("" FILES ${SRC})

# Creating target
add_executable(${PRJ_NAME} ${SRC} )
add_dependencies(${PRJ_NAME} Sbregaciamesa)

set_target_properties(${PRJ_NAME}  PROPERTIES DEBUG_POSTFIX "d")

# Add linked libraries by configuration
target_link_libraries( ${PRJ_NAME} debug Deckd optimized Deck )
target_link_libraries( ${PRJ_NAME} debug Cardd optimized Card )
target_link_libraries( ${PRJ_NAME} debug Sbregaciamesad optimized Sbregaciamesa )
# Use the Widgets module from Qt 5
target_link_libraries(${PRJ_NAME} Qt5::Widgets)