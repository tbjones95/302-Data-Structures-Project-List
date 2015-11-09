cmake_minimum_required(VERSION 3.3)
project(Project_7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    AcctType.cpp
    AcctType.h
    BSTClass.cpp
    BSTClass.h
    NameData
    PA07.cpp
    SimpleTimer.cpp
    SimpleTimer.h)

add_executable(Project_7 ${SOURCE_FILES})