cmake_minimum_required(VERSION 3.8)
project(DuskDawn VERSION 0.1.0)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/DuskDawn/cmake/Modules/)

option(SHARED_LIBS "static linking or dynamic linking" ON)

set(DEBUG_MODE ON CACHE BOOL "Whether to build in Debug or Release")

include(DuskDawnBuildSet)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/DuskDawn/DDConfig.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/DDConfig.h)
               
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(DuskDawn)
add_subdirectory(Sandbox)
