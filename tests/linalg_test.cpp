#include <gtest/gtest.h>
#include <linalg/linalg.hpp>
#include <nda/gtest_tools.hpp>
#include <nda/nda.hpp>

TEST(Linalg, PrintLibInfo) { linalg::print_lib_info(); }

TEST(Linalg, SolveLinearSystem) {
    auto A = nda::matrix<double, nda::F_layout>{{1, 2}, {3, 4}};
    auto b = nda::vector<double>{5, 6};
    auto x = linalg::solve_linear_system(A, b);
    EXPECT_ARRAY_NEAR(x, nda::vector<double>{-4, 4.5}, 1e-10);
}