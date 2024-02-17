#ifndef E8127378_1747_4CFA_905C_9E1F39FFB206
#define E8127378_1747_4CFA_905C_9E1F39FFB206

#include <iomanip>
#include <iostream>
#include <vector>

class Matrix {
private:
  int n;
  std::vector<std::vector<double>> data;

public:
  explicit Matrix(int size);

  int get_size() const;

  Matrix(int size, std::vector<std::vector<double>> &array);

  std::vector<double> &operator[](int i);

  void print() const;

  void swap_rows(int row_1, int row_2) {
    auto temp = data[row_1];
    data[row_1] = data[row_2];
    data[row_2] = temp;
  }

  ~Matrix();
};

#endif /* E8127378_1747_4CFA_905C_9E1F39FFB206 */
