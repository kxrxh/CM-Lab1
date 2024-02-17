#ifndef BF08F08D_7717_4388_82E2_46206A4B74C9
#define BF08F08D_7717_4388_82E2_46206A4B74C9

#include "matrix.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

Matrix read_matrix(const char *filename);

std::ifstream open_file(const char *filename);

#endif /* BF08F08D_7717_4388_82E2_46206A4B74C9 */
