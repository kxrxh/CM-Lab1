#ifndef CD64C5C8_4D1B_4E80_AE3C_5E6313DBB1B9
#define CD64C5C8_4D1B_4E80_AE3C_5E6313DBB1B9

#include <complex>
#include <iomanip>
#include <iostream>
#include <sstream>

#define draw_line()                                                            \
  std::cout << "-----------------------------------------------------------\n"

/**
 * Formats a double value for pretty printing, with optional precision.
 *
 * If the double is very close to an integer value, prints it as an integer
 * for readability. Otherwise, prints it as a fixed point double with the
 * given precision.
 *
 * @param x The double value to format
 * @param prec The precision to use for fixed point if needed.
 * @return The pretty-printed string representation of the double.
 */
std::string pretty_double(double x, int prec);

#endif /* CD64C5C8_4D1B_4E80_AE3C_5E6313DBB1B9 */
