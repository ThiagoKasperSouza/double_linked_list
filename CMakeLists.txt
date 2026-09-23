cmake_minimum_required(VERSION 3.10)
project(c_linked_list C)

set(CMAKE_C_STANDARD 11)
include_directories(src/lib)

file(GLOB SOURCES "src/*c")

add_executable(program ${SOURCES})


