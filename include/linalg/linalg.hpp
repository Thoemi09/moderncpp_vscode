#pragma once

#include <nda/nda.hpp>

namespace linalg {

  /**
   * @brief Print some information about the library.
   */
  void print_lib_info();

  /**
   * @brief Solve a linear system \f$ A \mathbf{x} = \mathbf{b} \f$.
   *
   * @param A The matrix \f$ A \f$.
   * @param b The right-hand side vector \f$ \mathbf{b} \f$.
   * @return The solution vector \f$ \mathbf{x} \f$.
   */
  nda::vector<double> solve_linear_system(nda::matrix<double, nda::F_layout> const &A, nda::vector<double> const &b);

} // namespace linalg