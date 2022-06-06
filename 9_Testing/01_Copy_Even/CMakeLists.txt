cmake_minimum_required(VERSION 3.23)
project(01_Copy_Even)

set(CMAKE_CXX_STANDARD 20)

add_executable(01_Copy_Even main.cpp test_runner.cpp test_runner.h profiler.cpp profiler.h)
