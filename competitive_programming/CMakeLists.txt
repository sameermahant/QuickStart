# ======================================================================
# Mandatory cmake command
# ======================================================================
cmake_minimum_required(VERSION 3.20)

# ======================================================================
# Project specific settings
# ======================================================================
project(SampleProgram
        VERSION 1.0.0.0
        DESCRIPTION "Sample program for competitive coding problems"
        HOMEPAGE_URL "https://github.com/sameermahant/QuickStart"
        LANGUAGES CXX)

# ======================================================================
# Common CMake settings
# ======================================================================
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(COMPILER_FLAGS "-march=core2 -fno-var-tracking -fexceptions -finline-functions")
set(COMPILER_WARRNINGS "-Wall -Werror -Wextra -Wno-unused-function -Wno-deprecated-declarations -Wno-sign-compare -Wunused-parameter -Wignored-qualifiers -Wtype-limits -Wduplicated-cond -Wno-class-memaccess")

set(CMAKE_CXX_FLAGS "${COMPILER_FLAGS} ${COMPILER_WARRNINGS}")

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message("Setting build type to 'Release' as none was specified.")
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# ======================================================================
# External libraries / packages
# ======================================================================

# ======================================================================
# Test
# ======================================================================

# ======================================================================
# Coverage
# ======================================================================

# ======================================================================
# Package information
# ======================================================================

# ======================================================================
# Summary
# ======================================================================
message(STATUS "=== ${CMAKE_PROJECT_NAME} ===")
message(STATUS "Project version     : ${CMAKE_PROJECT_VERSION}")
message(STATUS "Project description : ${CMAKE_PROJECT_DESCRIPTION}")
message(STATUS "Project homepage URL: ${CMAKE_PROJECT_HOMEPAGE_URL}")
message(STATUS "CMake build type    : ${CMAKE_BUILD_TYPE}")

# ======================================================================
# Custom Commands
# ======================================================================
add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/input.txt"
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/input.txt" "${CMAKE_CURRENT_BINARY_DIR}"
    DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/input.txt"
    )
add_custom_target(copy_input_file DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/input.txt")

# ======================================================================
# Targets / Subdirectories
# ======================================================================
add_executable(SampleProgram.exe "")
target_sources(AntlrApp
    PRIVATE
        Main.cpp
)
target_link_libraries(SampleProgram.exe stdc++)
add_dependencies(SampleProgram.exe copy_input_file)
set_target_properties(SampleProgram.exe PROPERTIES
    RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time"
)
