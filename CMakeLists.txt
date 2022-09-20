cmake_minimum_required(VERSION 3.23)
project(Lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab1 src/main.cpp src/Node.h src/CircularLinkedList.cpp src/CircularLinkedList.h src/Node.cpp)
