cmake_minimum_required(VERSION 3.25.1)
project(neoskye)

set(CMAKE_CXX_STANDARD 17) # latest clang supported version

set(CMAKE_C_CLANG_TIDY "clang-tidy")
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

add_subdirectory(lib) # build extendal libraries

add_library(neoskye
    src/Neoskye.cpp
)
target_link_libraries(neoskye sfml-window sfml-audio)