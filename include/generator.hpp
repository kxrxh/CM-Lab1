#ifndef C6F3CEB1_66F6_4954_A657_48D31A33785F
#define C6F3CEB1_66F6_4954_A657_48D31A33785F

#include "matrix.hpp"

/**
 * Generates a matrix of random double values with dimensions size x size.
 * Uses a random number engine and uniform distribution to generate values
 * between -100 and 100. Populates the matrix by iterating through rows and
 * columns, assigning a random value to each element. Returns the generated
 * matrix.
 */
Matrix generate_matrix(int size);

#endif /* C6F3CEB1_66F6_4954_A657_48D31A33785F */
