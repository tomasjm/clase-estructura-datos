cmake_minimum_required(VERSION 3.28)

project(Punto)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)
add_executable(ejecutable_punto src/main.cpp src/punto.cpp)

