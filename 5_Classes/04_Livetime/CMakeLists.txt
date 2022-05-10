cmake_minimum_required(VERSION 3.17)
project(04_Livetime)

set(CMAKE_CXX_STANDARD 20)

add_executable(04_Livetime main.cpp)
add_compile_options(-fno-elide-constructors)