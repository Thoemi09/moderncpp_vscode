#include <linalg/linalg.hpp>

#include <nda/nda.hpp>

#include <format>
#include <iostream>
#include <stdexcept>

namespace linalg {

  void print_lib_info() { std::cout << "linalg library version 0.1\n"; }

  nda::vector<double> solve_linear_system(nda::matrix<double, nda::F_layout> const &A, nda::vector<double> const &b) {
    // perform LU factorization
    auto ipiv = nda::vector<int>(b.size());
    auto LU   = A;
    auto info = nda::lapack::getrf(LU, ipiv);
    if (info != 0) throw std::runtime_error{std::format("Error: nda::lapack::getrf failed with error code {}", info)};

    // solve the linear system
    nda::matrix<double, nda::F_layout> x(b.size(), 1);
    x(nda::range::all, 0) = b;
    info                  = nda::lapack::getrs(LU, x, ipiv);
    if (info != 0) throw std::runtime_error{std::format("Error: nda::lapack::getrs failed with error code {}", info)};
    return x(nda::range::all, 0);
  }

} // namespace linalg