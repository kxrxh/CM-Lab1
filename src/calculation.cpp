#include "calculation.hpp"
#include "utils.hpp"

const double EPSILON = 1e-10;

/**
 * Prints the residual vector for the given matrix m and result vector.
 * Checks that the sizes match, then computes each residual as r_i = m_i - Ax_i
 * where A is the matrix m, x is result_vec, and r_i is the ith residual.
 * Prints each residual value.
 */
void print_residual_vector(Matrix &m, std::vector<double> &result_vec) {
  std::cout << "Residual vector:" << std::endl;
  if (result_vec.size() != m.get_size()) {
    std::cout << "Error: size of residual vector is not equal to size of matrix"
              << std::endl;
    return;
  }
  for (int i = 0; i < m.get_size(); i++) {
    double res = 0;
    for (int j = 0; j < m.get_size(); j++) {
      res += m[i][j] * result_vec[j];
    }
    double r = m[i][m.get_size()] - res;
    std::cout << "r" << i + 1 << " = " << r << std::endl;
  }
}

/**
 * Performs Gaussian elimination on the given matrix m.
 * Prints the original matrix, matrix after elimination, determinant,
 * and residual vector. Returns the solution vector if one exists.
 */
std::vector<double> gauss_elimination(Matrix &m) {
  const int n = m.get_size();
  std::cout << "Matrix before Gaussian elimination:" << std::endl;
  m.print();

  Matrix old_m = m.copy();

  double det = 1.0; // Initialize determinant

  for (int i = 0; i < n; i++) {
    double max_el = std::fabs(m[i][i]);
    int max_row = i;

    for (int k = i + 1; k < n; k++) {
      if (std::fabs(m[k][i]) > max_el) {
        max_el = std::fabs(m[k][i]);
        max_row = k;
      }
    }

    // Swap current row with the row containing maximum element
    if (max_row != i) {
      m.swap_rows(i, max_row);
      det *= -1; // Change the sign of determinant for row swaps
    }

    // Check if the pivot element is too close to zero
    if (std::fabs(m[i][i]) < EPSILON) {
      det = 0;
      // Skip this column, it's effectively zero
      continue;
    }

    // Update determinant
    det *= m[i][i];

    // Perform Gaussian elimination to make elements below the pivot zero
    for (int k = i + 1; k < n; k++) {
      double factor = m[k][i] / m[i][i];
      for (int j = i; j <= n; j++) {
        m[k][j] -= factor * m[i][j];
      }
    }
  }
  std::cout << "Matrix determinant: " << pretty_double(det, 3) << std::endl;
  if (det == 0) {
    std::cout << "Determinant is zero, no solution exists." << std::endl;
    return {};
  }

  draw_line();

  std::cout << "Matrix after Gaussian elimination:" << std::endl;
  m.print();

  // Back substitution to solve for unknowns
  std::vector<double> result(n);
  for (int i = n - 1; i >= 0; i--) {
    result[i] = m[i][m.get_size()];
    for (int j = i + 1; j < n; j++) {
      result[i] -= m[i][j] * result[j];
    }
    result[i] /= m[i][i]; // divide by diagonal element
  }

  draw_line();
  print_residual_vector(old_m, result);

  return result;
}
