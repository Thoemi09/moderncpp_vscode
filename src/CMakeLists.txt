# build library
add_library(linalg)
add_library(moderncpp::linalg ALIAS linalg)
target_sources(linalg PRIVATE linalg.cpp)

# link to nda
target_link_libraries(linalg PUBLIC nda::nda_c)

# set include directories
target_include_directories(linalg PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>)