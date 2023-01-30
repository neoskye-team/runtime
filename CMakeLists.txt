cmake_minimum_required(VERSION 3.25.1)
project(neoskye)

set(CMAKE_CXX_STANDARD 17) # latest clang supported version

if(DEFINED ENV{NSFINDSFML})
    find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
  else()
    add_subdirectory(lib) # build external libraries
endif()

set(NEOSKYE_SOURCE_DIR src/neoskye)

add_library(neoskye
# namespace neoskye
    ${NEOSKYE_SOURCE_DIR}/Neoskye.cpp
    ${NEOSKYE_SOURCE_DIR}/EngineOptions.cpp
    ${NEOSKYE_SOURCE_DIR}/Entity.cpp
    ${NEOSKYE_SOURCE_DIR}/View.cpp
    ${NEOSKYE_SOURCE_DIR}/Input.cpp

    # namespace neoskye::content
    ${NEOSKYE_SOURCE_DIR}/content/ContentLoader.cpp
    ${NEOSKYE_SOURCE_DIR}/content/TextData.cpp
    ${NEOSKYE_SOURCE_DIR}/content/Sprite.cpp

    # namespace neoskye::graphics
    ${NEOSKYE_SOURCE_DIR}/graphics/SpriteBatch.cpp
)
target_link_libraries(neoskye sfml-window sfml-graphics)
target_include_directories(neoskye PUBLIC src)
target_compile_options(neoskye PRIVATE "-Wall")
target_compile_options(neoskye PRIVATE "-Wextra")
target_compile_options(neoskye PRIVATE "-pedantic")

if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    target_compile_options(neoskye PRIVATE -fsanitize=address,undefined)
    target_link_options(neoskye PRIVATE -fsanitize=address,undefined)
endif()
