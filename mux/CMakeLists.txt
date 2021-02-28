cmake_minimum_required(VERSION 3.10)

project(xnet)

add_library(mux STATIC
    cmux.cpp
    cmuxfactory.cpp
    cmuxepoll.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
