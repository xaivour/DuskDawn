######################################
# DuskDawn
######################################

add_subdirectory(vendor EXCLUDE_FROM_ALL)

set(DD_SOURCE)
set(DD_HEADERS)

list(APPEND DD_SOURCE
    DuskDawn.cpp
)

list(APPEND DD_HEADERS
    DuskDawn.h
)

include(src/CMakeLists.txt)

set(DD_ALL_SOURCES ${DD_SOURCE} ${DD_HEADERS} ${DD_CORE})

if(SHARED_LIBS)
add_library(DuskDawn SHARED ${DD_ALL_SOURCES})
else()
add_library(DuskDawn STATIC ${DD_ALL_SOURCES})
endif()

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
        DD_SHARED_BUILD
    PUBLIC
        DD_SHARED
)
else()
target_compile_definitions(DuskDawn
    PUBLIC
        DD_STATIC
)
endif()



