cmake_minimum_required(VERSION 3.21)
project(01_static)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-O0)

add_executable(01_static main.cpp other.h)
