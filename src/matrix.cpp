#include "matrix.hpp"
#include "utils.hpp"

Matrix::Matrix(int size) : n(size) {
  std::vector<std::vector<double>> m(n);
  for (int i = 0; i < n; i++) {
    m[i].resize(n + 1);
  }

  data = std::move(m);
}

Matrix::Matrix(int size, std::vector<std::vector<double>> &array)
    : n(size), data(std::move(array)) {}

int Matrix::get_prec() const { return prec; }

int Matrix::get_size() const { return n; }

void Matrix::set_prec(int pers) { prec = pers; }

Matrix Matrix::copy() const {
  Matrix m(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      m[i][j] = data[i][j];
    }
  }
  m.prec = this->prec;
  return m;
}

std::vector<double> &Matrix::operator[](int i) { return data[i]; }

void Matrix::print() const {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      std::cout << std::setw(10) << pretty_double(data[i][j], this->prec)
                << (j == n - 1 ? " | " : " ");
    }
    std::cout << std::endl;
  }
}

double Matrix::get_determinant() const {
  switch (n) {
  case 1:
    return data[0][0];
    break;
  case 2:
    return data[0][0] * data[1][1] - data[0][1] * data[1][0];
    break;
  default:
    double det = 0;
    for (int j = 0; j < n; j++) {
      Matrix minor(n - 1);
      for (int i = 1; i < n; i++) {
        for (int k = 0; k < n; k++) {
          if (k < j) {
            minor[i - 1][k] = data[i][k];
          } else if (k > j) {
            minor[i - 1][k - 1] = data[i][k];
          }
        }
      }
      det += (j % 2 == 0 ? 1 : -1) * data[0][j] * minor.get_determinant();
    }
    return det;
    break;
  }
}

Matrix::~Matrix() {}