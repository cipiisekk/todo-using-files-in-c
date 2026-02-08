cmake_minimum_required(VERSION 3.20)
project(TodoWithFilesInC LANGUAGES C)

add_executable(TodoApp
	main.c
	src/apputils.c
	src/strutils.c
	src/fileutils.c
	src/todo.c
)

target_include_directories(TodoApp PRIVATE include)
