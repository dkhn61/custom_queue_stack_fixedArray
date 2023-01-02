cmake_minimum_required(VERSION 3.23)
project(composition_source)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(composition_source
        Array.cpp
        Array.h
        Array.inl
        Fixed_Array.cpp
        Fixed_Array.h
        Stack.cpp
        Stack.h
        Stack.inl
        Queue.cpp
        Queue.h
        Queue.inl
        driver.cpp)