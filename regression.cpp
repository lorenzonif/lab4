#include "regression.hpp"

Result fit(Regression const &reg) {
  // the following call would fail compilation if the fit method weren't const
  return reg.fit();
}

void Regression::add(double x, double y){
    ++N_;
    sum_x_ += x;
    sum_y_ += y;
    sum_xy_ += x * y;
    sum_x2_ += x * x;
}

int Regression::size() const { return N_; }