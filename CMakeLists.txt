cmake_minimum_required(VERSION 3.16)
project(xo)

set(CMAKE_CXX_STANDARD 17)

add_executable(xo main.cpp Table.cpp Table.h utils.cpp utils.h)
target_link_libraries(xo PUBLIC "-static")