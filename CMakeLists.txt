cmake_minimum_required(VERSION 3.21)
project(dataStructure_trees)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(dataStructure_trees
        BST.cpp
        BST.h
        main.cpp)
