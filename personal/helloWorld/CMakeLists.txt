cmake_minimum_required(VERSION 3.0)

project(helloWorld)

add_executable(helloWorld
    src/main.cpp
    src/hello.cpp
    )

#target_include_directories(helloWorld PUBLIC ./headers)
