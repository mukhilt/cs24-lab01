cmake_minimum_required(VERSION 4.1)
project(STARTER_lab01)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(STARTER_lab01
        intlist.cpp
        intlist.h
        testlist.cpp
        testrest.cpp)
