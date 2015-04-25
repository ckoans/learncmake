cmake_minimum_required(VERSION 2.6)
project(Tutorial)

# enable `make test`
enable_testing()

# Should we use our custom functions?
option(USE_CUSTOM "Use custom functions" ON)

# Set version number
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)

# Configure header file
# TutorialConfig.h gets generated
# taking declarations from TutorialConfig.h.in
configure_file(
    "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
    "${PROJECT_BINARY_DIR}/TutorialConfig.h"
    )

# our binary directory is also the directory that contains TutorialConfig.h
# which we need to include
include_directories("${PROJECT_BINARY_DIR}")

# Specify directories we want to include
if (USE_CUSTOM)
    include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
    add_subdirectory(MathFunctions)
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_CUSTOM)

add_executable(Tutorial tutorial.cpp)

# Link to our included library
target_link_libraries(Tutorial ${EXTRA_LIBS})

# Installation
# CMAKE_INSTALL_PREFIX can be used to provide install root
install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)

# Name of test is TutorialRuns
# test command that will be executed is `./Tutorial 25`
# It's not a very useful test but it shows us that ./Tutorial command works
add_test(TutorialRuns Tutorial 25)

# does it sqrt of 25?
add_test(TutorialComp25 Tutorial 25)
set_tests_properties(TutorialComp25
    PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5")
set_tests_properties(TutorialComp25
    PROPERTIES PASS_REGULAR_EXPRESSION "gives us 50")

# does it handle negative number?
add_test(TutorialNegative Tutorial -25)
set_tests_properties(TutorialNegative
    PROPERTIES PASS_REGULAR_EXPRESSION "-25 is 0")

# does it handle small numbers?
add_test(TutorialSmall Tutorial 0.0001)
set_tests_properties(TutorialSmall
    PROPERTIES PASS_REGULAR_EXPRESSION "0.0001 is 0.01")

# does the usage message work?
add_test(TutorialUsage Tutorial)
set_tests_properties(TutorialUsage
    PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number")
