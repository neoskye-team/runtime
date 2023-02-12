cmake_minimum_required(VERSION 3.24)
project(neoskye)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib) # build external libraries

add_subdirectory(bin)

if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    # target_compile_options(neoskye_runner PRIVATE -fsanitize=address,undefined)
    # target_link_options(neoskye_runner PRIVATE -fsanitize=address,undefined)
endif()