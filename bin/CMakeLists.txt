add_executable(neoskye_runner
    main.cpp
    Vector2.cpp
    EngineOptions.cpp
    SdlGLWindow.cpp
)

target_link_libraries(neoskye_runner SDL2::SDL2 SDL2::SDL2main)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(neoskye_runner PRIVATE "-W3")
else()
    target_compile_options(neoskye_runner PRIVATE "-Wall")
    target_compile_options(neoskye_runner PRIVATE "-Wextra")
    target_compile_options(neoskye_runner PRIVATE "-pedantic")
endif()

if (WIN32)
    target_compile_options(neoskye_runner PRIVATE "--for-linker=/SUBSYSTEM:WINDOWS")
endif()

target_include_directories(neoskye_runner PRIVATE ${NEOSKYE_RUNNER_INCLUDE_DIR})
