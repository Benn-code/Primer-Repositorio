#include <iostream>
#include <cmath>
#include <functional> // Para std::function

// Definición de la función para la cual queremos encontrar la derivada
double f(double x) {
    // Aquí puedes reemplazar la función con la que desees
    return std::sin(x);
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
    double step_size = 0.001;

    // Calcular la derivada numérica
    double numerical_derivative = derivative_sixth_order(f, x_point, step_size);

    // Calcular la derivada analítica para comparación (para f(x) = sin(x), f'(x) = cos(x))
    double analytical_derivative = std::cos(x_point);

    std::cout << "Punto x: " << x_point << std::endl;
    std::cout << "Tamaño del paso h: " << step_size << std::endl;
    std::cout << "Derivada numérica (orden O(h^6)): " << numerical_derivative << std::endl;
    std::cout << "Derivada analítica: " << analytical_derivative << std::endl;
    std::cout << "Error absoluto: " << std::abs(numerical_derivative - analytical_derivative) << std::endl;

    return 0;
}