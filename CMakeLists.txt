cmake_minimum_required (VERSION 3.3 FATAL_ERROR)

set (PROJECT_NAME Boardgames)
project (${PROJECT_NAME} CXX C)

set (Boardgames_VERSION_MAJOR 0)
set (Boardgames_VERSION_MINOR 1)

add_subdirectory(Grid  "${CMAKE_CURRENT_BINARY_DIR}/Grid")
add_subdirectory(SquareGrid "${CMAKE_CURRENT_BINARY_DIR}/SquareGrid")
add_subdirectory(HexGrid "${CMAKE_CURRENT_BINARY_DIR}/HexGrid")
