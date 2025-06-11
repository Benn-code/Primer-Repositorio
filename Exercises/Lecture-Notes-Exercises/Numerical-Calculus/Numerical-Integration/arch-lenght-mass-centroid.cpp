#include <iostream>
#include <cmath>
#include <iomanip>
#include <functional> // Para std::function

// Incluye tu archivo de encabezado de integración
#include "integration.h" 

// --- Funciones para el Problema 1: Catenaria ---
// Integrando para la longitud de arco de y = cosh(x)
double integrand_catenary_arc_length(double x) {
    return std::cosh(x); // sqrt(1 + (sinh(x))^2) = cosh(x)
}

// --- Funciones para el Problema 2: Cadena y = x^2, rho = |x| ---
// Integrando para la longitud de arco de y = x^2
double integrand_chain_arc_length(double x) {
    return std::sqrt(1.0 + 4.0 * x * x); // sqrt(1 + (2x)^2)
}

// Integrando para la masa total M (rho * ds)
double integrand_chain_mass(double x) {
    return std::abs(x) * std::sqrt(1.0 + 4.0 * x * x); // |x| * sqrt(1 + (2x)^2)
}

// Integrando para el numerador de y_bar (y * rho * ds)
double integrand_chain_y_bar_numerator(double x) {
    return x * x * std::abs(x) * std::sqrt(1.0 + 4.0 * x * x); // x^2 * |x| * sqrt(1 + (2x)^2)
}

int main() {
    // Parámetros de integración
    const double A = -1.0;
    const double B = 1.0;
    const int N_INTERVALS = 10000; // Número de intervalos para Simpson
    // Puedes usar también tus funciones de cuadratura Gaussiana para mayor precisión
    // Por ejemplo, gauss7 o gauss13.

    std::cout << std::fixed << std::setprecision(10); // Formato de salida

    // --- Problema 1: Longitud de Arco de la Catenaria y = cosh(x) ---
    std::cout << "--- Problema 1: Longitud de Arco de la Catenaria y = cosh(x) ---\n";
    std::cout << "Rango: x = " << A << " a x = " << B << "\n";
    
    double arc_length_catenary_simpson = simpson(A, B, N_INTERVALS, integrand_catenary_arc_length);
    double arc_length_catenary_gauss7 = gauss7(A, B, integrand_catenary_arc_length);
    double arc_length_catenary_gauss13 = gauss13(A, B, integrand_catenary_arc_length);

    std::cout << "Longitud de arco (Simpson, N=" << N_INTERVALS << "): " << arc_length_catenary_simpson << "\n";
    std::cout << "Longitud de arco (Gauss Orden 7):          " << arc_length_catenary_gauss7 << "\n";
    std::cout << "Longitud de arco (Gauss Orden 13):         " << arc_length_catenary_gauss13 << "\n";
    // Para comparación con la solución analítica
    std::cout << "Solucion Analitica (2 * sinh(1)):        " << 2.0 * std::sinh(1.0) << "\n";
    std::cout << "\n";

    // --- Problema 2: Cadena con y = x^2, rho = |x| ---
    std::cout << "--- Problema 2: Cadena con y = x^2, densidad rho = |x| ---\n";
    std::cout << "Rango: x = " << A << " a x = " << B << "\n";
    
    // 1. Longitud de Arco
    double arc_length_chain_simpson = simpson(A, B, N_INTERVALS, integrand_chain_arc_length);
    double arc_length_chain_gauss7 = gauss7(A, B, integrand_chain_arc_length);
    
    std::cout << "1. Longitud de arco:\n";
    std::cout << "   (Simpson, N=" << N_INTERVALS << "): " << arc_length_chain_simpson << "\n";
    std::cout << "   (Gauss Orden 7):          " << arc_length_chain_gauss7 << "\n";

    // 2. Masa Total M
    double total_mass_M_simpson = simpson(A, B, N_INTERVALS, integrand_chain_mass);
    double total_mass_M_gauss7 = gauss7(A, B, integrand_chain_mass);

    std::cout << "2. Masa total M:\n";
    std::cout << "   (Simpson, N=" << N_INTERVALS << "): " << total_mass_M_simpson << "\n";
    std::cout << "   (Gauss Orden 7):          " << total_mass_M_gauss7 << "\n";

    // 3. Posición x del Centroide (x_bar)
    // El numerador de la integral es la integral de una función impar sobre un intervalo simétrico.
    // Analíticamente, es 0. Numéricamente, debería ser muy cercano a 0.
    double x_bar_numerator_simpson = simpson(A, B, N_INTERVALS, [](double x){ return x * std::abs(x) * std::sqrt(1.0 + 4.0 * x * x); });
    double x_bar_numerator_gauss7 = gauss7(A, B, [](double x){ return x * std::abs(x) * std::sqrt(1.0 + 4.0 * x * x); });
    
    std::cout << "3. Posición x del Centroide (x_bar):\n";
    std::cout << "   Numerador (Simpson):      " << x_bar_numerator_simpson << "\n";
    std::cout << "   Numerador (Gauss Orden 7):" << x_bar_numerator_gauss7 << "\n";
    std::cout << "   Denominador (Masa Total): " << total_mass_M_gauss7 << "\n"; // Usamos la masa calculada
    
    std::cout << "   Por simetria, x_bar = 0.0\n";
    
    // 4. Posición y del Centroide (y_bar)
    double y_bar_numerator_simpson = simpson(A, B, N_INTERVALS, integrand_chain_y_bar_numerator);
    double y_bar_numerator_gauss7 = gauss7(A, B, integrand_chain_y_bar_numerator);

    std::cout << "4. Posición y del Centroide (y_bar):\n";
    std::cout << "   Numerador (Simpson):      " << y_bar_numerator_simpson << "\n";
    std::cout << "   Numerador (Gauss Orden 7):" << y_bar_numerator_gauss7 << "\n";
    std::cout << "   Denominador (Masa Total): " << total_mass_M_gauss7 << "\n"; // Usamos la masa calculada

    double y_bar = y_bar_numerator_gauss7 / total_mass_M_gauss7; // Usamos el resultado de Gauss para el cálculo final
    std::cout << "   y_bar = " << y_bar << "\n";

    return 0;
}