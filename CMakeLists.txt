cmake_minimum_required(VERSION 3.24)
project(moderncpp_vscode
    VERSION 0.1.0
    LANGUAGES CXX)

#########################
# Project wide setup
#########################
enable_testing()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_VERBOSE_MAKEFILE ON)

#########################
# User/Build options
#########################
option(VSC_BUILD_TESTS "Build unit tests with googletest" ON)
option(VSC_BUILD_EXAMPLES "Build examples" ON)

# output user options
message(STATUS "===============================================")
message(STATUS "Start configuring project ${PROJECT_NAME}")
message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "===============================================")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Build shared libs: ${BUILD_SHARED_LIBS}")
message(STATUS "Build unit tests: ${VSC_BUILD_TESTS}")
message(STATUS "Build examples: ${VSC_BUILD_EXAMPLES}")
message(STATUS "===============================================")

#########################
# Build targets
#########################
add_subdirectory(deps)
add_subdirectory(src)
if(VSC_BUILD_TESTS)
    add_subdirectory(tests)
endif()
if(VSC_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
