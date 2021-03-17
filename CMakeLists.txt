cmake_minimum_required(VERSION 3.16)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

file(GLOB UnionFind "*.h" "*.cpp")

add_executable(untitled main.cpp Parser.h Parser.cpp Graph.cpp Graph.h ${UnionFind})