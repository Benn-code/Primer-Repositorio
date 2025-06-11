#include <iostream> // Para std::cout
#include <vector>   // No estrictamente necesario, pero útil para almacenar si se quiere
#include <cmath>    // Para std::tgamma, std::pow
#include <iomanip>  // Para std::fixed, std::setprecision

int main() {
    // Parámetros de la distribución Gamma (puedes cambiarlos)
    const double ALPHA = 7.5; // alpha (k_shape en algunas nomenclaturas)
    const double BETA = 1.0;  // beta (theta_scale = 1/beta_rate en algunas nomenclaturas)

    // Imprimir los parámetros de la distribución
    std::cout << "Calculando los primeros diez momentos para la Distribucion Gamma:\n";
    std::cout << "  Alpha (shape) = " << ALPHA << "\n";
    std::cout << "  Beta (rate)   = " << BETA << "\n";
    std::cout << "--------------------------------------------------\n";
    std::cout << "Momento (k)\tValor del Momento <x^k>\n";
    std::cout << "--------------------------------------------------\n";

    // Calcular el valor de Gamma(alpha) una sola vez, ya que es constante
    double gamma_alpha = std::tgamma(ALPHA);

    // Verificar si gamma_alpha es cero o muy pequeño para evitar divisiones por cero
    if (gamma_alpha == 0.0 || std::abs(gamma_alpha) < 1e-18) {
        std::cerr << "Error: Gamma(alpha) es cero o demasiado pequeño, no se pueden calcular los momentos.\n";
        return 1;
    }

    // Calcular los primeros diez momentos (k desde 1 hasta 10)
    for (int k = 1; k <= 10; ++k) {
        // Calcular Gamma(k + alpha)
        double gamma_k_plus_alpha = std::tgamma(k + ALPHA);

        // Calcular beta^k
        double beta_k = std::pow(BETA, k);

        // Calcular el k-ésimo momento usando la fórmula analítica
        double moment_k = (gamma_k_plus_alpha / gamma_alpha) / beta_k;

        // Imprimir el resultado con precisión formateada
        std::cout << std::fixed << std::setprecision(8) 
                  << std::setw(9) << k << "\t\t" 
                  << std::setw(15) << moment_k << "\n";
    }

    std::cout << "--------------------------------------------------\n";

    return 0;
}