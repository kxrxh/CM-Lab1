#include "calculation.hpp"
#include <complex>

const double EPSILON = 1e-10;

std::vector<double> gauss_elimination(Matrix &m) {
  int n = m.get_size();
  for (int i = 0; i < n; i++) {
    double max_el = std::fabs(m[i][i]);
    int max_row = i;

    for (int k = i + 1; k < n; k++) {
      if (std::fabs(m[k][i]) > max_el) {
        max_el = std::fabs(m[k][i]);
        max_row = k;
      }
    }

    if (max_row != i) {
      m.swap_rows(i, max_row);
    }
    // Check if the pivot element is too close to zero
    if (std::fabs(m[i][i]) < EPSILON) {
      // Skip this column, it's effectively zero
      continue;
    }

    for (int k = i + 1; k < n; k++) {
      double factor = m[k][i] / m[i][i];
      for (int j = i; j <= n; j++) {
        m[k][j] -= factor * m[i][j];
      }
    }
  }

  std::cout << "Matrix after gauss elimination:" << std::endl;
  m.print();

  std::vector<double> result(n);

  for (int i = n - 1; i >= 0; i--) {
    result[i] = m[i][m.get_size()];
    for (int j = i + 1; j < n; j++) {
      result[i] -= m[i][j] * result[j];
    }
    result[i] /= m[i][i];
    // round result[i] to 10 decimal places
    // result[i] = std::round(result[i] * 10000000000) / 10000000000;
  }

  return result;
}
