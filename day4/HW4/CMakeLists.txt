cmake_minimum_required(VERSION 3.5)

project(lamda LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lamda main.cpp student.h lamda.cpp)
