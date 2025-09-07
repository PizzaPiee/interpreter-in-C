cmake_minimum_required(VERSION 3.15...4.0)

project(MazLang VERSION 1.0
		DESCRIPTION "My Programming Language"
		LANGUAGES C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

add_executable(maz main.c)
