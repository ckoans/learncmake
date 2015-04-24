cmake_minimum_required(VERSION 2.6)
project (Tutorial)

# Set version number
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# Configure header file
configure_file (
    "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
    "${PROJECT_BINARY_DIR}/TutorialConfig.h"
    )

include_directories("${PROJECT_BINARY_DIR}")

add_executable(Tutorial tutorial.cpp)
