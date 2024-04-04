cmake_minimum_required(VERSION 3.13)

project(sqlite_test)

add_executable(
    sqlite_test
    src/main.cpp
    src/connector.cpp
)

#header files
#set(HEADERS
#    headers/connector.h
#)
#target_include_directories(sqlite_test PRIVATE ${HEADERS}

#include headerfiles

target_include_directories(sqlite_test PRIVATE ./headers)

# Add the SQLite connector files
add_library(sqlite3 ./lib/sqlite3.c)
target_include_directories(sqlite3 PUBLIC ./lib)

# Link your executable with the SQLite connector library
target_link_libraries(sqlite_test PRIVATE sqlite3)
