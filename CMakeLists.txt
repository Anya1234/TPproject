cmake_minimum_required(VERSION 3.10)
project(LOTR)

set(CMAKE_CXX_STANDARD 11)

include_directories(source)

add_subdirectory(source)
add_subdirectory(test)
add_subdirectory(lib/googletest)