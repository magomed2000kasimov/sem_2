cmake_minimum_required(VERSION 3.13)
project(kanikuli C)

set(CMAKE_C_STANDARD 99)

add_executable(kanikuli main.c tree.h tree.c)