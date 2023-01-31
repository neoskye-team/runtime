cmake_minimum_required(VERSION 3.25.1)
project(neoskye)

set(CMAKE_CXX_STANDARD 17) # latest clang supported version

if(DEFINED ENV{NEOSKYE_USE_SYSTEM_SFML})
    find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
  else()
    add_subdirectory(lib) # build external libraries
endif()

add_subdirectory(src/neoskye)
add_subdirectory(src/nsphysics)

# these must be relative to the root cmake so includes don't mess everything up
add_library(__neoskye SHARED ${NEOSKYE_SOURCES})

target_link_libraries(__neoskye PRIVATE sfml-window sfml-graphics)
target_compile_options(__neoskye PRIVATE "-Wall")
target_compile_options(__neoskye PRIVATE "-Wextra")
target_compile_options(__neoskye PRIVATE "-pedantic")
target_include_directories(__neoskye PUBLIC src)
if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    target_compile_options(__neoskye PRIVATE -fsanitize=address,undefined)
    target_link_options(__neoskye PRIVATE -fsanitize=address,undefined)
endif()

add_library(__nsphysics ${NSPHYSICS_SOURCES})

target_link_libraries(__nsphysics PRIVATE sfml-window sfml-graphics)
target_compile_options(__nsphysics PRIVATE "-Wall")
target_compile_options(__nsphysics PRIVATE "-Wextra")
target_compile_options(__nsphysics PRIVATE "-pedantic")
target_include_directories(__nsphysics PUBLIC src)
if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    target_compile_options(__nsphysics PRIVATE -fsanitize=address,undefined)
    target_link_options(__nsphysics PRIVATE -fsanitize=address,undefined)
endif()

add_library(neoskye::engine ALIAS __neoskye)
add_library(neoskye::physics ALIAS __nsphysics)