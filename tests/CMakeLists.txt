# create test executables
add_executable(linalg_test linalg_test.cpp)
target_link_libraries(linalg_test PRIVATE moderncpp::linalg GTest::gtest_main)

# add tests
add_test(NAME linalg_test COMMAND linalg_test)