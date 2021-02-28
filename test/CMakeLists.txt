cmake_minimum_required(VERSION 3.10)

project(testxnet)

add_executable(testxnet
    test.cpp
)

target_link_libraries(testxnet
    xnet
)

include_directories(${CMAKE_SOURCE_DIR}/include)
