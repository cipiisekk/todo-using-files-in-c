cmake_minimum_required(VERSION 3.16)
project(todo_with_files C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(todo
    main.c
    todo.c
    fileutils.c
    strutils.c
    apputils.c
)

target_include_directories(todo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(todo PRIVATE -Wall -Wextra -Wpedantic)

