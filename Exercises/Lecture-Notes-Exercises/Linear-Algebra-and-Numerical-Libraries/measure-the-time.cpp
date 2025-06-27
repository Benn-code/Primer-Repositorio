#include <iostream>
#include <Eigen/Dense>      // Para operaciones con matrices y vectores de Eigen
#include <chrono>           // Para medir el tiempo
#include <vector>           // Para almacenar los tamaños N a probar

//g++ time_axb.cpp -o time_axb -I/usr/include/eigen3 -O3 -std=c++17

int main() {
    std::cout << "Midiendo el tiempo de resolución de Ax=b como función de N\n";
    std::cout << "----------------------------------------------------------\n";

    // Define un rango de tamaños N para probar.
    // Puedes ajustar estos valores según la capacidad de tu máquina y el tiempo que desees esperar.
    // Se recomienda ir aumentando N de forma no lineal (ej. 100, 200, 400, 800...)
    // para ver mejor la tendencia de crecimiento.
    std::vector<int> N_values = {100, 200, 400, 800, 1500, 2000}; // Valores de N a probar

    // Iterar sobre cada valor de N
    for (int N : N_values) {
        // 1. Crear una matriz A y un vector b aleatorios de tamaño N x N y N x 1, respectivamente
        std::cout << "\nGenerando matriz A y vector b de tamaño N = " << N << "...\n";

        // Eigen::MatrixXd::Random(N, N) crea una matriz de N x N con valores aleatorios
        // distribuidos uniformemente en el rango [-1, 1].
        Eigen::MatrixXd A = Eigen::MatrixXd::Random(N, N);

        // Eigen::VectorXd::Random(N) crea un vector de N elementos con valores aleatorios.
        Eigen::VectorXd b = Eigen::VectorXd::Random(N);

        // 2. Medir el tiempo para computar la solución x

        // Registrar el tiempo de inicio
        auto start_time = std::chrono::high_resolution_clock::now();

        // Resolver el sistema Ax = b.
        // Seguimos usando ColPivHouseholderQR por su buen balance entre velocidad y robustez.
        // Para N muy grandes, podrías considerar otras descomposiciones si conoces las propiedades de A.
        Eigen::VectorXd x = A.colPivHouseholderQr().solve(b);

        // Registrar el tiempo de fin
        auto end_time = std::chrono::high_resolution_clock::now();

        // Calcular la duración en milisegundos
        std::chrono::duration<double, std::milli> duration_ms = end_time - start_time;

        std::cout << "  Tiempo de cálculo para N = " << N << ": " << duration_ms.count() << " ms\n";

        // Opcional: Verificar la precisión de la solución para N
        // (Solo para N pequeños, ya que para N muy grandes, la impresión de A*x es costosa)
        // std::cout << "  Verificación: ||A*x - b|| = " << (A * x - b).norm() << std::endl;
    }

    std::cout << "\nMedición de tiempo completada.\n";
    return 0;
}