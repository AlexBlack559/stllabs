cmake_minimum_required (VERSION 2.6)

project (lab2)

set("${PROJECT}_BINARY_DIR" bin)
set("${PROJECT}_SOURCE_DIR" src:include)
set("${PROJECT}_LIB_DIR" lib)

add_executable(lab2 src/main.cpp)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)

set (CMAKE_INCLUDE_PATH ${${PROJECT}_SOURCE_DIR})
set (CMAKE_LIBRARY_PATH ${${PROJECT}_LIB_DIR})
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/${${PROJECT}_BINARY_DIR})
set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_BUILD_TYPE Debug)
