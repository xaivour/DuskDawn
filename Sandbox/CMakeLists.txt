cmake_minimum_required(VERSION 3.8)
project(Sandbox)

add_executable(Sandbox src/main.cpp)

target_link_libraries(Sandbox
	PUBLIC
		DuskDawn::DuskDawn
)
