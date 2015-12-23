cmake_minimum_required (VERSION 3.3 FATAL_ERROR)

set (PROJECT_NAME Utilities)
project (${PROJECT_NAME} CXX C)

set (${PROJECT_NAME}_VERSION_MAJOR 0)
set (${PROJECT_NAME}_VERSION_MINOR 1)

#add_subdirectory(Card  "grid")
add_subdirectory(Die  "die")
#add_subdirectory(Deck  "deck")
#add_subdirectory(Hand  "hand")