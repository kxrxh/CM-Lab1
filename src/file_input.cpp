#include "file_input.hpp"

void replaceAll(std::string &str, const std::string &from,
                const std::string &to) {
  if (from.empty())
    return;
  size_t start_pos = 0;
  while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
    str.replace(start_pos, from.length(), to);
    start_pos += to.length();
  }
}

std::ifstream open_file(const char *filename) {
  std::ifstream f(filename);
  if (!f.good()) {
    std::string err = "Could not open file: ";
    err += filename;
    throw std::runtime_error(err);
  }

  return f;
}

Matrix read_matrix(const char *filename) {
  auto file = open_file(filename);

  std::string content(std::istreambuf_iterator<char>(file), {});

  replaceAll(content, ",", ".");

  std::stringstream ss(content);

  int size, prec;
  ss >> prec;
  ss >> size;

  std::vector<std::vector<double>> matrix =
      std::vector<std::vector<double>>(size);
  for (int i = 0; i < size; i++) {
    matrix[i].resize(size + 1);
    for (int j = 0; j <= size; j++) {
      ss >> matrix[i][j];
    }
  }

  auto m = Matrix(size, matrix);
  m.set_prec(prec);

  return m;
}
