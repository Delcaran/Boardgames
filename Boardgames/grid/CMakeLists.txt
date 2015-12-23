cmake_minimum_required (VERSION 3.3 FATAL_ERROR)

set (PROJECT_NAME Grid)
project (${PROJECT_NAME} CXX C)

set (${PROJECT_NAME}_VERSION_MAJOR 0)
set (${PROJECT_NAME}_VERSION_MINOR 1)

# adding project headers
include(inc/add_headers.in)

# adding dependencies headers

# cleaning headers
list(REMOVE_DUPLICATES PROJECT_INCLUDE_DIRS)
include_directories(${PROJECT_INCLUDE_DIRS})

# adding sources
include(src/add_sources.in)
# adding tests
include(test/add_sources.in)

message(STATUS "--------- ${PROJECT_NAME} ---------")
message(STATUS "SOURCES = ${PROJECT_SOURCES}")
message(STATUS "HEADERS = ${PROJECT_HEADERS}")
message(STATUS "INCLUDE = ${PROJECT_INCLUDE_DIRS}")

add_library(${PROJECT_NAME} 
  SHARED 
  ${PROJECT_SOURCES} 
  ${PROJECT_HEADERS} 
)

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
