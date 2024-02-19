#include "generator.hpp"
#include <random>


Matrix generate_matrix(int size) {
  Matrix matrix(size);
  std::default_random_engine eng(static_cast<unsigned>(std::time(nullptr)));
  std::uniform_real_distribution<double> dist(-100, 100.0);

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j <= size; ++j) {
      matrix[i][j] = dist(eng); // Assign random values to each element
    }
  }

  return matrix;
}