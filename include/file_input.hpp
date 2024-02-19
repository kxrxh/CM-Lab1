#ifndef BF08F08D_7717_4388_82E2_46206A4B74C9
#define BF08F08D_7717_4388_82E2_46206A4B74C9

#include "matrix.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

/**
 * Reads a matrix from the given file.
 *
 * The file should contain the matrix in txt format, with the number of rows and
 * precision specified on the first line. The remaining lines contain the matrix
 * data.
 *
 * The data is read into a Matrix object, with the precision set.
 *
 * @param filename The name of the file to read from
 * @return The Matrix object containing the data read from the file
 */
Matrix read_matrix(const char *filename);

/**
 * Opens the file with the given filename.
 * Throws a runtime_error if the file could not be opened.
 */
std::ifstream open_file(const char *filename);

#endif /* BF08F08D_7717_4388_82E2_46206A4B74C9 */
