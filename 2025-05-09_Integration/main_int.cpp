#include <iostream>
#include <fstream>
#include "integration.h"

double fun(double x);

int main(void) {
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);
    
    std::cout << trapezoid(0.0, 1.0, 10, fun) << "\n";
    std::cout << trapezoid(0.0, 1.0, 1000, fun) << "\n";
    std::cout << trapezoid(0.0, 1.0, 10000000, fun) << "\n";

    return 0;
}

double fun(double x){
    return x*x;
}