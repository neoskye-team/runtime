cmake_minimum_required(VERSION 3.24)
set(NEOSKYE_RUNNER_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(bin)

if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    # target_compile_options(neoskye_runner PRIVATE -fsanitize=address,undefined)
    # target_link_options(neoskye_runner PRIVATE -fsanitize=address,undefined)
endif()