cmake_minimum_required (VERSION 3.3 FATAL_ERROR)

set (PROJECT_NAME Hand)
project (${PROJECT_NAME} CXX C)

set (${PROJECT_NAME}_VERSION_MAJOR 0)
set (${PROJECT_NAME}_VERSION_MINOR 1)

# adding project headers
include(inc/add_headers.in)

# adding dependencies headers
set(PROJECT_DEPENDENCIES card deck)
foreach(_dep ${PROJECT_DEPENDENCIES})
  list(APPEND PROJECT_INCLUDE_DIRS ../${_dep}/inc)
endforeach()

# cleaning headers
list(REMOVE_DUPLICATES PROJECT_INCLUDE_DIRS)
include_directories(${PROJECT_INCLUDE_DIRS})

# adding sources
include(src/add_sources.in)

message(STATUS "--------- ${PROJECT_NAME} ---------")
message(STATUS "SOURCES = ${PROJECT_SOURCES}")
message(STATUS "HEADERS = ${PROJECT_HEADERS}")
message(STATUS "INCLUDE = ${PROJECT_INCLUDE_DIRS}")

add_library(${PROJECT_NAME} 
  SHARED 
  ${PROJECT_SOURCES} 
  ${PROJECT_HEADERS} 
)

target_link_libraries(${PROJECT_NAME} Deck)

set_target_properties(
	${PROJECT_NAME}
	PROPERTIES
	DEBUG_OUTPUT_NAME ${PROJECT_NAME}_d
	RELEASE_OUTPUT_NAME ${PROJECT_NAME}
	PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}.h"
	COMPILE_FLAGS ""
)

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}
	RUNTIME DESTINATION bin COMPONENT Runtime
  LIBRARY DESTINATION lib COMPONENT Runtime
	ARCHIVE DESTINATION lib COMPONENT Runtime
	PUBLIC_HEADER DESTINATION inc COMPONENT Runtime
)
