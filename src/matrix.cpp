#include "matrix.hpp"

Matrix::Matrix(int size) : n(size) {
  std::vector<std::vector<double>> m(n);
  for (int i = 0; i < n; i++) {
    m[i].resize(n + 1);
  }

  data = std::move(m);
}

int Matrix::get_size() const { return n; }

Matrix::Matrix(int size, std::vector<std::vector<double>> &array)
    : n(size), data(std::move(array)) {}

std::vector<double> &Matrix::operator[](int i) { return data[i]; }

void Matrix::print() const {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      std::cout << std::setw(8) << data[i][j] << (j == n - 1 ? " | " : " ");
    }
    std::cout << std::endl;
  }
}

Matrix::~Matrix() {}