cmake_minimum_required(VERSION 3.12)
project(HSM)

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_STANDARD 14)

add_subdirectory (src)
add_subdirectory (test)