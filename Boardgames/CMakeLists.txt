cmake_minimum_required (VERSION 3.3 FATAL_ERROR)

set (PROJECT_NAME Boardgames)
project (${PROJECT_NAME} CXX C)

set (${PROJECT_NAME}_VERSION_MAJOR 0)
set (${PROJECT_NAME}_VERSION_MINOR 1)

add_subdirectory(Grid  "grid")
add_subdirectory(SquareGrid "squaregrid")
add_subdirectory(Checkerboard "checkerboard")
add_subdirectory(Checkerboard_Canada "checkerboard_canada")
add_subdirectory(Checkerboard_International "checkerboard_international")
add_subdirectory(Chessboard "chessboard")
add_subdirectory(Checkerboard_Italian "checkerboard_italian")
