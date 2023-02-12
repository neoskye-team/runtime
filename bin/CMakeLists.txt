set(NEOSKYE_RUNNER_DIR bin)

set(NEOSKYE_RUNNER_SOURCES

PARENT_SCOPE)

add_executable(neoskye_runner
    main.cpp
    Vector2.cpp
    EngineOptions.cpp
    SdlGLWindow.cpp
)

target_link_libraries(neoskye_runner SDL2::SDL2 SDL2::SDL2main)
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(neoskye_runner PRIVATE "-Wall")
    target_compile_options(neoskye_runner PRIVATE "-W4")
else()
    target_compile_options(neoskye_runner PRIVATE "-Wall")
    target_compile_options(neoskye_runner PRIVATE "-Wextra")
    target_compile_options(neoskye_runner PRIVATE "-pendantic")
endif()
if (WIN32)
    target_link_options(neoskye_runner PRIVATE "/SUBSYSTEM:WINDOWS")
    target_compile_definitions(neoskye_runner PRIVATE NEOSKYE_WINMAIN)
endif()
target_include_directories(neoskye_runner PRIVATE ${CMAKE_SOURCE_DIR})
