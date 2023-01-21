cmake_minimum_required(VERSION 3.25.1)
project(neoskye)

set(CMAKE_CXX_STANDARD 17) # latest clang supported version

add_subdirectory(lib) # build extendal libraries

add_library(neoskye
    src/Neoskye.cpp
    src/EngineOptions.cpp
)
target_link_libraries(neoskye sfml-window sfml-audio)
target_include_directories(neoskye PUBLIC src)

if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    target_compile_options(neoskye PRIVATE "-fsanitize=address,undefined")
endif()