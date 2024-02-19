#include "utils.hpp"


std::string pretty_double(double x, int prec) {
  std::stringstream oss;

  if (std::fabs(x - std::round(x)) < 1e-9) {
    oss << std::fixed << std::setprecision(0) << std::round(x);
  } else {
    oss << std::fixed << std::setprecision(prec) << x;
  }

  return oss.str();
}