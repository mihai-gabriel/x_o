cmake_minimum_required(VERSION 3.16)
project(xo)

set(CMAKE_CXX_STANDARD 17)

add_executable(xo src/main.cpp src/Table.cpp src/Table.h src/utils.cpp src/utils.h)
target_link_libraries(xo PUBLIC "-static")