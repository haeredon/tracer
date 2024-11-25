cmake_minimum_required(VERSION 3.25)

# set the project name and version
project(Tracer VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_BUILD_TYPE Debug)


add_subdirectory(src)
add_subdirectory(test)
