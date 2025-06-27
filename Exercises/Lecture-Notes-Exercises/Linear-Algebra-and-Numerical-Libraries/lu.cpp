// lu.cpp
#include <iostream>
#include <Eigen/Dense>      // Para operaciones con matrices y vectores de Eigen
#include <chrono>           // Para medir el tiempo
#include <vector>           // Para almacenar los tamaños N a probar

// g++ lu.cpp -o lu -I/usr/include/eigen3 -O3 -std=c++17

int main() {
    std::cout << "Midiendo el tiempo de resolución de Ax=b con FullPivLU como función de N\n";
    std::cout << "----------------------------------------------------------------------\n";

    // Define un rango de tamaños N para probar.
    // FullPivLU es más lenta que ColPivHouseholderQR, así que podríamos usar un rango
    // de N un poco menor o esperar más tiempo.
    std::vector<int> N_values = {100, 200, 400, 800, 1000, 1200}; // Valores de N a probar

    // Iterar sobre cada valor de N
    for (int N : N_values) {
        // 1. Crear una matriz A y un vector b aleatorios de tamaño N x N y N x 1
        std::cout << "\nGenerando matriz A y vector b de tamaño N = " << N << "...\n";

        Eigen::MatrixXd A = Eigen::MatrixXd::Random(N, N);
        Eigen::VectorXd b = Eigen::VectorXd::Random(N);

        // 2. Medir el tiempo para computar la solución x usando FullPivLU

        // Registrar el tiempo de inicio
        auto start_time = std::chrono::high_resolution_clock::now();

        // Resolver el sistema Ax = b usando FullPivLU
        Eigen::VectorXd x = A.fullPivLu().solve(b);

        // Registrar el tiempo de fin
        auto end_time = std::chrono::high_resolution_clock::now();

        // Calcular la duración en milisegundos
        std::chrono::duration<double, std::milli> duration_ms = end_time - start_time;

        std::cout << "  Tiempo de cálculo para N = " << N << ": " << duration_ms.count() << " ms\n";

        // Opcional: Verificar la precisión de la solución
        // std::cout << "  Verificación: ||A*x - b|| = " << (A * x - b).norm() << std::endl;
    }

    std::cout << "\nMedición de tiempo completada.\n";
    return 0;
}