cmake_minimum_required(VERSION 3.10)

project(xnet)

add_library(dispatcher STATIC
    cdispatcher.cpp
    cdispatcherfactory.cpp
    ceventhandler.cpp
    cworker.cpp
    croundrobinbalancer.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/assert/include)

target_link_libraries(dispatcher
    pthread
)

add_subdirectory(test)
