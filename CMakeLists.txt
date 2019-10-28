cmake_minimum_required(VERSION 3.12)
project(graphs-asdasd)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -pthread)


add_executable(graphs-asdasd graph.h parser.h graph.cpp main.cpp)