cmake_minimum_required(VERSION 3.13)

project(hw)

project(hw CXX)  # Explicitly specify the C++ language

set(CMAKE_CXX_STANDARD 11)    # Set the desired C++ standard

add_executable(
    hw
    run.cpp
    contact_list.cpp)

set(HEADERS
    contact_list.h)

target_include_directories(hw PRIVATE ${HEADERS})
