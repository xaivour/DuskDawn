######################################
# DuskDawn
######################################
cmake_minimum_required(VERSION 3.8)
project(DuskDawn VERSION 0.1.0)

add_subdirectory(vendor EXCLUDE_FROM_ALL)

set(DD_SOURCE)
set(DD_HEADERS)

list(APPEND DD_SOURCE
    DuskDawn.cpp
)

list(APPEND DD_HEADERS
    DuskDawn.h
)

set(DD_ALL_SOURCES ${DD_SOURCE} ${DD_HEADERS})

if(SHARED_LIBS)
add_library(DuskDawn SHARED ${DD_ALL_SOURCES})
else()
add_library(DuskDawn STATIC ${DD_ALL_SOURCES})
endif()

add_subdirectory(src)

target_link_libraries(DuskDawn
    PUBLIC
        Vendor::Spdlog
        Vendor::GLFW
        Vendor::Glad
)

target_include_directories(DuskDawn
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if(SHARED_LIBS)
target_compile_definitions(DuskDawn
    PRIVATE
        -DDD_SHARED_BUILD
    INTERFACE
        -DDD_SHARED
)
else()
target_compile_definitions(DuskDawn
    PUBLIC
        -DDD_STATIC
)
endif()

add_library(DuskDawn::DuskDawn ALIAS DuskDawn)



