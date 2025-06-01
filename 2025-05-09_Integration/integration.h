#pragma once
#include <cmath>
#include <functional>

//std::cout << trapezoid(0.0, 1.0, 10, fun) << "\n";

using fptr = std::function<double(double)>;

double trapezoid (double a, double b, int N, fptr fun);

using algptr = std::function<double(double, double, fptr)>;
