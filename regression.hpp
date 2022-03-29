#ifndef REGRESSION_HPP
#define REGRESSION_HPP

#include <stdexcept>

struct Result {
  double A;
  double B;
};

class Regression {
  int N_{};
  double sum_x_{};
  double sum_y_{};
  double sum_xy_{};
  double sum_x2_{};

 public:
  int size() const;

  void add(double x, double y);

  Result fit() const {
    if (N_ < 2) {
      throw std::runtime_error{"Not enough points to run a fit"};
    }
    double const d = N_ * sum_x2_ - sum_x_ * sum_x_;
    if (d == 0.) {
      throw std::runtime_error{"Trying to fit a vertical line"};
    }
    double const a = (sum_y_ * sum_x2_ - sum_x_ * sum_xy_) / d;
    double const b = (N_ * sum_xy_ - sum_x_ * sum_y_) / d;
    return {a, b};
  }
};

Result fit(Regression const &reg);

#endif