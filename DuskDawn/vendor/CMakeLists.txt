cmake_minimum_required(VERSION 3.8)
project(Vendor) 

add_subdirectory(glfw)

add_library(Vendor::GLFW ALIAS glfw)

add_subdirectory(glm)

add_library(Vendor::GLM ALIAS glm)

add_subdirectory(spdlog)

add_library(Vendor::Spdlog ALIAS spdlog)

add_library(glad STATIC glad/src/glad.c)

target_include_directories(glad 
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/glad/include
)

if(LINUX OR MACOSX)
target_link_libraries(glad 
    PUBLIC
        GL
)
elseif(WINDOWS)
target_link_libraries(glad
    PUBLIC
        Opengl32
)
endif()

add_library(Vendor::Glad ALIAS glad)

