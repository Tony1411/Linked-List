cmake_minimum_required(VERSION 3.20)
project(list_with_iterator)

set(CMAKE_CXX_STANDARD 17)

add_executable(list_with_iterator main.cpp node.h list.h double.h forward.h iterator.h)
