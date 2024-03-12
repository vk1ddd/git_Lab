cmake_minimum_required(VERSION 3.26)
project(git_lab C)

set(CMAKE_C_STANDARD 11)

add_executable(git_lab main.c
        libs/data_structures/vector/vector.h
        libs/data_structures/vector/vector.c)
