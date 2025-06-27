#include <iostream>
#include <Eigen/Dense>

// g++ your_file_name.cpp -o solve_system -I/usr/include/eigen3 -O3 -std=c++17
./solve_system

int main() {
    // 1. Definir la matriz A y el vector b del sistema

    // Matriz A
    Eigen::MatrixXd A(3, 3);
    A << 150, -100,    0,
        -100,  150,  -50,
           0,  -50,   50;

    // Vector b
    Eigen::VectorXd b(3);
    b << 588.6,
         686.7,
         784.8;

    std::cout << "Matriz A:\n" << A << std::endl;
    std::cout << "\nVector b:\n" << b << std::endl;

    // 2. Resolver el sistema Ax = b utilizando LLT (Cholesky Decomposition)

    // LLT es la elección óptima para matrices simétricas y definidas positivas
    Eigen::VectorXd x = A.llt().solve(b);

    std::cout << "\nSolución x (usando LLT):\n" << x << std::endl;

    // 3. Verificar la solución (opcional pero buena práctica)
    // Calcula A*x y compara con b
    Eigen::VectorXd Ax_calculated = A * x;
    std::cout << "\nVerificación: A * x = \n" << Ax_calculated << std::endl;
    std::cout << "Diferencia ||A*x - b|| (debería ser cercana a cero) = " << (Ax_calculated - b).norm() << std::endl;

    return 0;
}