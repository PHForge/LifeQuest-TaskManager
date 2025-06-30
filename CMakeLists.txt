cmake_minimum_required(VERSION 3.10)

# Project Name and Version
project(LifeQuest VERSION 0.1 LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    src/main.cpp
    src/user.cpp
)

# Header files (optional, for IDEs)
set(HEADERS
    headers/user.hpp
)

# Create the executable
add_executable(LifeQuest ${SOURCES} ${HEADERS})

# Include header directories
target_include_directories(LifeQuest PRIVATE headers)

# Enable compiler warnings
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|MSVC")
    target_compile_options(LifeQuest PRIVATE -Wall -Wextra -Wpedantic)
endif()