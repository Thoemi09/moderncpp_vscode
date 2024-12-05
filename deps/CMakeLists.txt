# Find/Fetch various dependencies.
#
# The following dependencies are required:
# ---------------------------------
# nda: Multi-dimensional array library.
#
# The following dependencies are optional:
# ---------------------------------
# googletest: For testing. Only used if VSC_BUILD_TESTS is ON.

include(FetchContent)

#########################
# Required dependencies
#########################

# nda
FetchContent_Declare(nda
    GIT_REPOSITORY https://github.com/TRIQS/nda.git
    GIT_TAG unstable)
set(Build_Tests OFF CACHE BOOL "")
message(STATUS "-----------------------------------------------")
message(STATUS "Fetching nda ...")
FetchContent_MakeAvailable(nda)
message(STATUS "nda_SOURCE_DIR: ${nda_SOURCE_DIR}")
message(STATUS "-----------------------------------------------")

#########################
# Optional dedendencies
#########################

# googletest
if(VSC_BUILD_TESTS AND NOT TARGET gtest)
    FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG main)
    set(INSTALL_GTEST OFF CACHE BOOL "")
    set(BUILD_GMOCK OFF CACHE BOOL "")
    message(STATUS "-----------------------------------------------")
    message(STATUS "Fetching googletest ...")
    FetchContent_MakeAvailable(googletest)
    message(STATUS "googletest_SOURCE_DIR: ${googletest_SOURCE_DIR}")
    message(STATUS "-----------------------------------------------")
endif()
