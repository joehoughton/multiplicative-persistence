cmake_minimum_required(VERSION 3.6)
project(multiplicative-persistence)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(multiplicative-persistence ${SOURCE_FILES})