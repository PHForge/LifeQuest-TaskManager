# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name, version, and language
project(LifeQuest VERSION 0.1 LANGUAGES CXX)

# C++ standard settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Disable compiler-specific extensions

# Define source files
set(SOURCES
    src/main.cpp
    src/User.cpp
    src/Task.cpp
    src/TaskManager.cpp
)

# Define header files (optional, helps IDEs with code navigation)
set(HEADERS
    src/User.hpp
    src/Task.hpp
    src/TaskManager.hpp
)

# Create the executable
add_executable(LifeQuest ${SOURCES} ${HEADERS})

# Specify include directories
target_include_directories(LifeQuest PRIVATE src)

# Enable compiler warnings for better code quality
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|MSVC")
    target_compile_options(LifeQuest PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Optional: Ensure output directories for data files
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/data)