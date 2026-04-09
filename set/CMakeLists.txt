cmake_minimum_required(VERSION 3.10.0)
project(set VERSION 0.1.0 LANGUAGES C CXX)

add_executable(set
    main.cpp
    set.cpp
    Cell.cpp
    Iterator.cpp
    LinkedList.cpp
)

