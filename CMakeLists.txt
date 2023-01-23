cmake_minimum_required(VERSION 3.25.1)
project(neoskye)

set(CMAKE_CXX_STANDARD 17) # latest clang supported version

add_subdirectory(lib) # build extendal libraries

add_library(neoskye
# namespace neoskye
    src/Neoskye.cpp
    src/EngineOptions.cpp
    src/Entity.cpp
    src/View.cpp

    # namespace neoskye::content
    src/content/ContentLoader.cpp
    src/content/TextData.cpp
    src/content/Sprite.cpp
)
target_link_libraries(neoskye sfml-window sfml-graphics)
target_include_directories(neoskye PUBLIC src)
target_compile_options(neoskye PRIVATE "-Wall")
target_compile_options(neoskye PRIVATE "-Wextra")

if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    target_compile_options(neoskye PRIVATE -fsanitize=address)
    target_link_options(neoskye PRIVATE -fsanitize=address)
endif()