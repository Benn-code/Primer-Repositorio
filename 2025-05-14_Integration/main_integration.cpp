#include <iostream>
#include <cmath>
#include "integration.h"

double f(double x);

int main(void) {
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);

    std::cout << trapezoid(-1.0, 1.0, 10, f) << "\n";
    std::cout << trapezoid(-1.0, 1.0, 1000, f) << "\n";
    std::cout << trapezoid(-1.0, 1.0, 10000000, f) << "\n";

    std::cout << "Simpson:             " << simpson(-1.0, 1.0, 10, f) << "\n";

    std::cout << "Trapezoid+Richardson:"<< richardson(-1.0, 1.0, 10, f, trapezoid, 2) << "\n";

    std::cout << "Simpson+Richardson:  " << richardson(-1.0, 1.0, 10, f, simpson, 4) << "\n";

    std::cout << "Gauss 2:             "<< gauss2(-1.0, 1.0, f) << "\n";

    std::cout << "Gauss 3 con Vector:  "<< gauss3(-1.0, 1.0, f) << "\n";

    std::cout << "Gauss 5 con Vector:  "<< gauss5(-1.0, 1.0, f) << "\n";

    std::cout << "Gauss 7 con Vector:  "<< gauss7(-1.0, 1.0, f) << "\n";

    std::cout << "Gauss 13 con Vector: "<< gauss13(-1.0, 1.0, f) << "\n";

    std::cout << "Gauss 30 con Vector: "<< gauss30(-1.0, 1.0, f) << "\n";

    return 0;
}

double f(double x) {
    return 7*x*x*x -8*x*x + 3*x + 3;
    //Aproximación calculadora-de-integrales.com= 2/3= 0.6666666666666667
}


