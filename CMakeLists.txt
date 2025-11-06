cmake_minimum_required(VERSION 3.14)
project(Wordle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Executable
add_executable(wordle
    src/main.cpp
    src/WordList.cpp
    src/Game.cpp
    src/Renderer.cpp
    src/InputHandler.cpp
    src/Utils.cpp
)

# Include directories
target_include_directories(wordle PRIVATE include)

# Release mode optimizations
if(CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_options(wordle PRIVATE -O3)
endif()