cmake_minimum_required (VERSION 3.3 FATAL_ERROR)

project (Tabletop 
    VERSION 00.01.00.00
    LANGUAGES CXX C)

# Paths
set ( PROJECT_ROOT ${CMAKE_SOURCE_DIR}/src)
set ( TABLETOP_OUT_DIR ${CMAKE_SOURCE_DIR}/bin)
set ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TABLETOP_OUT_DIR} )
set ( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${TABLETOP_OUT_DIR} )
set ( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${TABLETOP_OUT_DIR} )

# Configure project generic rules
set(CMAKE_DEBUG_POSTFIX "d")

set(BOARDGAMES_DIR ${PROJECT_ROOT}/Boardgames)
set(UTILS_DIR ${PROJECT_ROOT}/Utilities)
set(GRID_INCLUDE ${UTILS_DIR}/grid/src)
set(SQUAREGRID_INCLUDE ${UTILS_DIR}/squaregrid/src)
set(HEXGRID_INCLUDE ${UTILS_DIR}/hexgrid/src)

# Add subprojects
add_subdirectory(${BOARDGAMES_DIR})
add_subdirectory(${UTILS_DIR})