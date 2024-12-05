# build examples
add_executable(ex1 ex1.cpp)
target_link_libraries(ex1 PRIVATE moderncpp::linalg)

add_executable(ex2 ex2.cpp)
target_link_libraries(ex2 PRIVATE moderncpp::linalg)

add_executable(ex3 ex3.cpp)
target_link_libraries(ex3 PRIVATE moderncpp::linalg)