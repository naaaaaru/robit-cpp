cmake_minimum_required(VERSION 3.5)

project(day3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(day3 main.cpp DataFrame.h vector.cpp)
