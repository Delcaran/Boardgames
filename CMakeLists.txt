cmake_minimum_required (VERSION 3.3 FATAL_ERROR)

set (PROJECT_NAME Boardgames)
project (${PROJECT_NAME} CXX C)

set (${PROJECT_NAME}_VERSION_MAJOR 0)
set (${PROJECT_NAME}_VERSION_MINOR 1)

add_subdirectory(Grid  "${CMAKE_CURRENT_BINARY_DIR}/Grid")
add_subdirectory(SquareGrid "${CMAKE_CURRENT_BINARY_DIR}/SquareGrid")
add_subdirectory(Checkerboard "${CMAKE_CURRENT_BINARY_DIR}/Checkerboard")
add_subdirectory(Checkerboard_Canada "${CMAKE_CURRENT_BINARY_DIR}/Checkerboard_Canada")
add_subdirectory(Checkerboard_International "${CMAKE_CURRENT_BINARY_DIR}/Checkerboard_International")
add_subdirectory(Chessboard "${CMAKE_CURRENT_BINARY_DIR}/Chessboard")
add_subdirectory(Checkerboard_Italian "${CMAKE_CURRENT_BINARY_DIR}/Checkerboard_Italian")
