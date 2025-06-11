#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <functional> // Para std::function
#include <stdexcept>  // Para std::runtime_error

// Incluye tu archivo de encabezado de integración
#include "integration.h" // Asegúrate de que este archivo exista en la misma carpeta o en el include path

// --- 1. La función a integrar para Li2(x) ---
// g(t) = ln(1-t) / t
double integrand(double t) {
    if (t == 0.0) {
        // La singularidad en t=0 es removible, el límite es -1.0.
        // Esto evita una división por cero cuando el método de integración evalúa en t=0.
        return -1.0; 
    }
    // Si t >= 1.0, ln(1.0 - t) sería inválido (ln(0) o ln(negativo)).
    // Sin embargo, el rango de integración es (0, x) donde x < 1.0,
    // por lo que t siempre estará < 1.0.
    return std::log(1.0 - t) / t;
}

// --- Función para calcular Li2(x) usando Simpson con Richardson Extrapolation ---
// Esto nos permite controlar la precisión de forma más efectiva.
double calculate_li2_simpson_richardson(double x_limit, double tolerance) {
    if (x_limit <= 0.0) return 0.0; // Li2(0) = 0 por definición de la integral

    // Número inicial de intervalos para Simpson. Debe ser par.
    // Un número pequeño para empezar a iterar.
    int N_initial = 2; 
    double Li2_val = 0.0;

    // Loop para encontrar N que cumpla la tolerancia usando Richardson
    // La extrapolación de Richardson para Simpson (orden alpha = 4)
    // es muy efectiva para estimar el error.
    // La función 'richardson' de tu librería es perfecta para esto.
    
    // Necesitamos una manera de saber si la tolerancia se cumple.
    // Podemos llamar a richardson y ver si la diferencia entre la mejor estimación
    // y la siguiente mejor estimación es menor que la tolerancia.
    // O podemos modificar richardson para que retorne también una estimación de error.
    // O simplemente llamar a simpson con un N y luego con 2N y usar richardson para comparar.

    // Para este problema, usaremos una estrategia iterativa simple
    // que duplica N y usa richardson para mejorar la precisión.
    // La 'tolerance' es sobre el resultado final de richardson.

    // La función richardson ya aplica simpson internamente.
    // Si queremos el error < 10^-6, richardson nos da una estimación de mayor orden.

    // Vamos a usar richardson para refinar la integral hasta que el error sea bajo.
    // La función richardson ya está diseñada para dar un resultado de mayor precisión.
    // El "error" en la pregunta se refiere a la precisión del resultado de la integral.
    // Podemos usar un N fijo lo suficientemente grande, o podemos hacerlo adaptativo.
    
    // Para simplificar y dado que richardson ya mejora el resultado:
    // Haremos un bucle que incrementa N para Simpson y usa Richardson.
    // Podríamos usar la diferencia entre dos resultados de Richardson con N y 2N intervalos.
    
    // Para el método de Simpson, la fórmula de error es O(h^4).
    // Si calculamos I_N (con N intervalos) y I_2N (con 2N intervalos),
    // la estimación de Richardson (orden alpha = 4) es: I_rich = (16*I_2N - I_N) / 15.
    // El error de I_2N es aproximadamente (I_2N - I_N) / 15.
    
    int N = N_initial;
    double current_Li2_simpson = 0.0;
    double prev_Li2_simpson = 0.0;
    double estimated_error = tolerance * 2; // Asegurarse de que el bucle se ejecute al menos una vez

    // ¡Importante! Li2(x) = -Integral. Así que el resultado de richardson debe ser negado.
    
    do {
        prev_Li2_simpson = current_Li2_simpson;
        // Llama a la función simpson de tu librería.
        // N_initial_simpson es el N para la llamada a simpson.
        // richardson(a, b, N_initial_simpson, f, simpson, 4)
        current_Li2_simpson = -richardson(0.0, x_limit, N, integrand, simpson, 4); 

        if (N > N_initial) { // Solo estimamos el error después de la segunda iteración
            estimated_error = std::fabs(current_Li2_simpson - prev_Li2_simpson) / 15.0; // Fórmula del error de Richardson
        }

        if (estimated_error < tolerance) {
            break; // Salir del bucle si el error estimado es menor que la tolerancia
        }
        
        N *= 2; // Duplicar el número de intervalos para la próxima iteración

        // Límite de seguridad para evitar un bucle infinito
        if (N > 1000000) { 
            std::cerr << "Advertencia: Simpson+Richardson no convergió con la tolerancia deseada para x=" << x_limit << ". N=" << N << std::endl;
            break; 
        }
    } while (true);

    return current_Li2_simpson;
}

int main() {
    // Rango para x
    const double X_MIN = 0.0;
    const double X_MAX = 0.999; // x debe ser menor que 1.0. Un límite cercano a 1.0, pero no 1.0.
    const double X_STEP = 0.005; // Paso para evaluar x (ajusta para mayor suavidad o rapidez)
    const double TOLERANCE = 1e-6; // Precisión requerida para Simpson+Richardson

    // Archivo de salida para los datos de la Di-logaritmo
    std::ofstream outputFile("dilogarithm_data.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo 'dilogarithm_data.txt' para escritura." << std::endl;
        return 1;
    }

    outputFile << std::fixed << std::setprecision(10); // Alta precisión para la salida
    outputFile << "# x\tLi2_simpson_richardson(x)\tLi2_gauss7(x)\tLi2_gauss13(x)\n";

    for (double x = X_MIN; x <= X_MAX; x += X_STEP) {
        // Calcular Li2(x) usando Simpson con Richardson
        double li2_simpson_rich = calculate_li2_simpson_richardson(x, TOLERANCE);

        // Calcular Li2(x) usando Cuadratura Gaussiana
        // Elegimos Gauss7 y Gauss13 para comparar su rendimiento
        double li2_gauss7 = -gauss7(0.0, x, integrand);    // ¡No olvides el signo negativo!
        double li2_gauss13 = -gauss13(0.0, x, integrand); // ¡No olvides el signo negativo!

        outputFile << x << "\t" << li2_simpson_rich << "\t" << li2_gauss7 << "\t" << li2_gauss13 << "\n";
    }

    outputFile.close();
    std::cout << "Datos de la función di-logaritmo guardados en 'dilogarithm_data.txt'\n";

    return 0;
}