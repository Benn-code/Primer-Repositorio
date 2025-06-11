#include <iostream>
#include <vector>
#include <cmath>    // Para exp, pow, tgamma
#include <fstream>  // Para std::ofstream
#include <iomanip>  // Para std::fixed, std::setprecision

// --- Constantes de la Distribución Gamma ---
const double ALPHA = 7.5;
const double BETA = 1.0;

// --- Nodos y Pesos para Cuadratura Gauss-Legendre (n=7) ---
// Estos valores son estándar para la integración en el intervalo [-1, 1]
const std::vector<double> GAUSS_NODES = {
    -0.9491079123427585,
    -0.7415311855994439,
    -0.4058451513773972,
     0.0,
     0.4058451513773972,
     0.7415311855994439,
     0.9491079123427585
};

const std::vector<double> GAUSS_WEIGHTS = {
    0.1294849661688697,
    0.2797053744387038,
    0.3818300505051189,
    0.4179591836734694,
    0.3818300505051189,
    0.2797053744387038,
    0.1294849661688697
};

// --- 1. Implementación de la Función de Densidad de Probabilidad (PDF) de Gamma ---
double gamma_pdf(double x, double alpha, double beta) {
    if (x < 0) return 0.0; // PDF es 0 para x < 0
    if (x == 0 && alpha < 1) return HUGE_VAL; // Podría tender a infinito, manejar con cuidado

    double term1 = std::pow(x, alpha - 1);
    double term2 = std::exp(-x / beta);
    double term3 = std::pow(beta, alpha);
    double term4 = std::tgamma(alpha); // Función Gamma (gamma(alpha))

    if (term3 == 0 || term4 == 0) { // Evitar división por cero
        return 0.0; // O manejar error
    }

    return (term1 * term2) / (term3 * term4);
}

// --- 2. Implementación del Método de Simpson para Integración Numérica ---
// func: la función a integrar (e.g., gamma_pdf)
// a: límite inferior de integración
// b: límite superior de integración
// n_intervals: número de subintervalos (DEBE SER PAR)
double integrate_simpson(double (*func)(double, double, double), double a, double b, int n_intervals) {
    if (n_intervals % 2 != 0) {
        std::cerr << "Error: El número de intervalos para Simpson debe ser par." << std::endl;
        return 0.0; // O manejar error
    }
    if (a == b) return 0.0; // Integral de un punto es 0
    if (a > b) return -integrate_simpson(func, b, a, n_intervals); // Si límites invertidos

    double h = (b - a) / n_intervals;
    double integral = func(a, ALPHA, BETA) + func(b, ALPHA, BETA); // f(x0) + f(xn)

    for (int i = 1; i < n_intervals; ++i) {
        double x_i = a + i * h;
        if (i % 2 == 0) { // Coeficiente 2 para índices pares
            integral += 2 * func(x_i, ALPHA, BETA);
        } else { // Coeficiente 4 para índices impares
            integral += 4 * func(x_i, ALPHA, BETA);
        }
    }

    return (h / 3) * integral;
}

// --- 3. Implementación de Cuadratura Gauss-Legendre ---
// func: la función a integrar
// a: límite inferior de integración
// b: límite superior de integración
double integrate_gaussian_quadrature(double (*func)(double, double, double), double a, double b) {
    if (a == b) return 0.0; // Integral de un punto es 0
    if (a > b) return -integrate_gaussian_quadrature(func, b, a); // Si límites invertidos

    double integral = 0.0;
    double c1 = (b - a) / 2.0;
    double c2 = (b + a) / 2.0;

    for (size_t i = 0; i < GAUSS_NODES.size(); ++i) {
        double x_mapped = c1 * GAUSS_NODES[i] + c2; // Mapear el nodo de [-1,1] a [a,b]
        integral += GAUSS_WEIGHTS[i] * func(x_mapped, ALPHA, BETA);
    }

    return c1 * integral;
}

// --- Función Principal ---
int main() {
    // Rango de x para la CDF
    const double X_MIN = 0.0;
    const double X_MAX = 20.0;
    const double X_STEP = 0.05; // Paso para evaluar x (más pequeño = más puntos, más suave la gráfica)

    // Número de intervalos para Simpson (asegúrate de que sea par y lo suficientemente grande)
    const int SIMPSON_INTERVALS = 1000; // Un valor razonable para precisión

    // Archivo de salida para los datos de la CDF
    std::ofstream outputFile("gamma_cdf_data.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo 'gamma_cdf_data.txt' para escritura." << std::endl;
        return 1;
    }

    // Escribir encabezado en el archivo
    outputFile << std::fixed << std::setprecision(10); // Para alta precisión en la salida
    outputFile << "# x\tF_simpson(x)\tF_gaussian(x)\n";

    // Calcular y escribir la CDF para cada x en el rango
    for (double x = X_MIN; x <= X_MAX; x += X_STEP) {
        double cdf_simpson = integrate_simpson(gamma_pdf, 0.0, x, SIMPSON_INTERVALS);
        double cdf_gaussian = integrate_gaussian_quadrature(gamma_pdf, 0.0, x);

        // La CDF debe ser entre 0 y 1. Pequeños errores numéricos pueden dar valores fuera.
        // Clamp los valores para que estén en [0, 1] si hay errores de redondeo.
        cdf_simpson = std::max(0.0, std::min(1.0, cdf_simpson));
        cdf_gaussian = std::max(0.0, std::min(1.0, cdf_gaussian));

        outputFile << x << "\t" << cdf_simpson << "\t" << cdf_gaussian << "\n";
    }

    outputFile.close();
    std::cout << "Datos de la CDF de la distribución Gamma guardados en 'gamma_cdf_data.txt'\n";

    return 0;
}