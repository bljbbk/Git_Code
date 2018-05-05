
project(log4cpp_project)

cmake_minimum_required(VERSION 2.6)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -O2")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O2")

#option(WIN64 "build on x64 platform" ON)

add_subdirectory(src)
