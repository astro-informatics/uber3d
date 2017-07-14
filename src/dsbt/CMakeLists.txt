cmake_minimum_required(VERSION 3.0)
include(ExternalProject)

project(dsbt)

# Using our own compiled version of boost
include(BuildBoost) # Custom module
include_directories(${Boost_INCLUDE_DIR} ${PYTHON_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIR})

set(DSBT_SRCS fastDSBT.cpp)

add_library(dsbt SHARED ${DSBT_SRCS})
add_dependencies(dsbt Boost)

target_link_libraries(dsbt ${Boost_LIBRARIES})
target_include_directories(dsbt INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
