cmake_minimum_required (VERSION 2.8.11)

project(Stardust_God)

file(GLOB_RECURSE SG_SOURCES "${PROJECT_SOURCE_DIR}/src/*.c*")
file(GLOB_RECURSE SG_HEADERS "${PROJECT_SOURCE_DIR}/src/*.h*")
include_directories("${PROJECT_SOURCE_DIR}/")

set(CMAKE_CXX_FLAGS "-std=c++1z ${CMAKE_CXX_FLAGS}")

add_executable(god ${SG_SOURCES})
