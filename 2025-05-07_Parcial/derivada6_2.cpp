#include <iostream>
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>
#include <vector>

// Definición de la función para la cual queremos encontrar la derivada
double f(double x) {
    return std::sin(x);
}

// Derivada analítica de f(x) = sin(x) es cos(x)
double analytical_derivative(double x) {
    return std::cos(x);
}

// Fórmula de diferenciación numérica de primer orden con error O(h^6)
double derivative_sixth_order(const std::function<double(double)>& func, double x, double h) {
    return ((1.0/60.0) * func(x - 3.0 * h)
           - (3.0/20.0) * func(x - 2.0 * h)
           + (3.0/4.0) * func(x - h)
           - (3.0/4.0) * func(x + h)
           + (3.0/20.0) * func(x + 2.0 * h)
           - (1.0/60.0) * func(x + 3.0 * h)) / h;
}

int main() {
    double x_point = 1.0;
    std::vector<double> h_values = {0.5, 0.2, 0.1, 0.05, 0.02, 0.01, 0.005, 0.002, 0.001};
    std::ofstream outfile("derivative_results.txt");

    if (outfile.is_open()) {
        outfile << std::setw(15) << "h"
                << std::setw(25) << "Derivada Numérica"
                << std::setw(25) << "Derivada Analítica"
                << std::setw(25) << "Error Absoluto" << std::endl;
        outfile << std::setfill('-') << std::setw(90) << "" << std::setfill(' ') << std::endl;

        for (double h : h_values) {
            double numerical_derivative = derivative_sixth_order(f, x_point, h);
            double exact_derivative = analytical_derivative(x_point);
            double error = std::abs(numerical_derivative - exact_derivative);

            outfile << std::setw(15) << std::fixed << std::setprecision(8) << h
                    << std::setw(25) << std::fixed << std::setprecision(15) << numerical_derivative
                    << std::setw(25) << std::fixed << std::setprecision(15) << exact_derivative
                    << std::setw(25) << std::fixed << std::setprecision(15) << error << std::endl;
        }
        outfile.close();
        std::cout << "Los resultados se han guardado en derivative_results.txt" << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo para escritura." << std::endl;
        return 1;
    }

    return 0;
}