cmake_minimum_required(VERSION 3.10)

project(xnet)

add_executable(testdispatcher
    testdispatcher.cpp
)

target_link_libraries(testdispatcher
    dispatcher
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/dispatcher/include)
