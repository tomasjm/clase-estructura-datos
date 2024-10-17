cmake_minimum_required(VERSION 3.28)
project(clase_12)

set(CMAKE_CXX_STANDARD 17)

add_executable(clase_12 stack.cpp
        linkedlist.h
        stack.h
        queue.h)
add_executable(clase_12_b queue.cpp
        linkedlist.h)
add_executable(clase_12_c queue_stack.cpp
        linkedlist.h
        stack.h )
