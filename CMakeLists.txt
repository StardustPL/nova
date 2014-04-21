cmake_minimum_required (VERSION 2.8.11)

project(Cosmos_God)

file(GLOB_RECURSE CG_SOURCES "${PROJECT_SOURCE_DIR}/src/*.c*")
file(GLOB_RECURSE CG_HEADERS "${PROJECT_SOURCE_DIR}/src/*.h*")
include_directories("${PROJECT_SOURCE_DIR}/")

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

add_executable(god ${CG_SOURCES})
