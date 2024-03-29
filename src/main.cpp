#include "calculation.hpp"
#include "file_input.hpp"
#include "generator.hpp"
#include "utils.hpp"
#include <iomanip>
#include <iostream>
#include <string.h>

void print_solution(std::vector<double> &solution) {
  draw_line();
  std::cout << "Solution vector:\n";
  int i = 1;
  for (auto &r : solution) {
    std::cout << "x" << i++ << " = " << pretty_double(r, 5) << "\n";
  }
}

int main(int argc, const char *argv[]) {
  if (argc == 1) {
    std::cout << "No arguments provided." << std::endl;
    std::cout << "Use -h flag to see the usage of program!" << std::endl;
    return 1;
  }

  if (argc == 2) {
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
      std::cout << "██       █████  ██████         ██ \n"
                   "██      ██   ██ ██   ██       ███ \n"
                   "██      ███████ ██████  █████  ██ \n"
                   "██      ██   ██ ██   ██        ██ \n"
                   "███████ ██   ██ ██████         ██ \n"
                << "\n\n";
      std::cout << "--help     -h              Print this message."
                << std::endl;
      std::cout << "--generate -g <size>       Generate matrix with given size."
                << std::endl;
      std::cout << "--file     -f <file_name>  Read matrix from file."
                << std::endl;
      std::cout << "--input    -i              Read matrix from stdin."
                << std::endl;
      return 0;
    }

    if (strcmp(argv[1], "-g") == 0 || strcmp(argv[1], "--generate") == 0) {
      std::cout << "Please provide size of matrix to generate." << std::endl;
      std::cout << "Usage:./lab1_cpp -g <size>" << std::endl;
      return 1;
    }

    if (strcmp(argv[1], "-f") == 0 || strcmp(argv[1], "--file") == 0) {
      std::cout << "Please provide a file to read from." << std::endl;
      std::cout << "Usage:./lab1_cpp -f <file_name>" << std::endl;
      return 1;
    }

    if (strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "--input") == 0) {
      std::cout << "Enter precision (ex: `5`): ";
      int prec;
      std::cin >> prec;

      std::cout << "Enter matrix size (ex: `3`): ";
      int size;
      std::cin >> size;

      std::vector<std::vector<double>> raw_matrix =
          std::vector<std::vector<double>>(size);
      std::cout << "Enter matrix elements row by row (ex: `1 2 3`): ";
      for (int i = 0; i < size; i++) {
        raw_matrix[i].resize(size + 1);
        for (int j = 0; j <= size; j++) {
          std::cin >> raw_matrix[i][j];
        }
      }

      auto m = Matrix(size, raw_matrix);
      m.set_prec(prec);
      auto result = gauss_elimination(m);
      print_solution(result);
    }
  }

  if (argc == 3) {
    if (strcmp(argv[1], "-f") == 0 || strcmp(argv[1], "--file") == 0) {
      auto matrix = read_matrix(argv[2]);
      auto result = gauss_elimination(matrix);
      print_solution(result);
    }

    if (strcmp(argv[1], "-g") == 0 || strcmp(argv[1], "--generate") == 0) {
      int size = atoi(argv[2]);
      auto matrix = generate_matrix(size);
      auto result = gauss_elimination(matrix);
      print_solution(result);
    }

    return 0;
  }
}