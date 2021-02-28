cmake_minimum_required(VERSION 3.10)

add_compile_options(-Wall -Werror)
add_compile_options(-fPIC)

set (CMAKE_C_FLAGS_DEBUG -g)
set (CMAKE_C_FLAGS_RELEASE -O2 -xx)

project(xnet)

add_subdirectory(test)
add_subdirectory(dispatcher)
add_subdirectory(mux)



add_library(xnet SHARED
    cxnetfactory.cpp
    cxnet.cpp
)

target_link_libraries(xnet
    -Wl,-whole-archive
    dispatcher
    mux
    -Wl,-no-whole-archive

    pthread
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/dispatcher/include)
include_directories(${CMAKE_SOURCE_DIR}/mux/include)

