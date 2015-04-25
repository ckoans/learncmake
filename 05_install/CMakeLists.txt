cmake_minimum_required(VERSION 2.6)
project(Tutorial)

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

install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)
