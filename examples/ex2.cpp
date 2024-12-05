#include <linalg/linalg.hpp>

int main() {
  // define the linear system of equations and the right hand side matrix
  auto A = nda::matrix<double, nda::F_layout>{{3, 2, -1}, {2, -2, 4}, {-1, 0.5, -1}};
  auto b = nda::vector<double>{1, -2, 0};
  std::cout << "A = " << A << std::endl;
  std::cout << "b = " << b << std::endl;

  // solve the linear system
  auto x = linalg::solve_linear_system(A, b);
  std::cout << "x = " << x << std::endl;

  // check the solution
  auto Ax = A * x;
  std::cout << "Ax = " << Ax << std::endl;
}