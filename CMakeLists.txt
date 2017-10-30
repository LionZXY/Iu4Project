cmake_minimum_required(VERSION 3.8)
project(Seminar2)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SOURCE_FILES
        "src/*.hpp"
        "src/*.cpp"
        "src/*.h"
        "src/*.c")

add_executable(Seminar2 ${SOURCE_FILES})