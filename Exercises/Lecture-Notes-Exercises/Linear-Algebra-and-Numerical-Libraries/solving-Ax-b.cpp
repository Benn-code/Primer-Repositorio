#include <iostream>
#include <vector>
#include <Eigen/Dense> // Incluye la cabecera para matrices y vectores densos

// Función para resolver el sistema Ax=b para una matriz A genérica
// y un vector b genérico usando Eigen.
// La matriz A debe ser cuadrada.
Eigen::VectorXd solveLinearSystemEigen(const Eigen::MatrixXd& A, const Eigen::VectorXd& b) {
    // Verificar si la matriz A es cuadrada
    if (A.rows() != A.cols()) {
        std::cerr << "Error: La matriz A no es cuadrada. La resolución de Ax=b requiere una matriz cuadrada." << std::endl;
        // Puedes lanzar una excepción o retornar un vector vacío/cero si lo prefieres
        return Eigen::VectorXd(); // Retorna un vector vacío en caso de error
    }

    // Verificar si el tamaño del vector b coincide con el número de filas de A
    if (A.rows() != b.rows()) {
        std::cerr << "Error: El número de filas de A no coincide con el número de elementos de b." << std::endl;
        return Eigen::VectorXd(); // Retorna un vector vacío en caso de error
    }

    std::cout << "Resolviendo el sistema Ax=b con Eigen..." << std::endl;
    std::cout << "\nMatriz A:\n" << A << std::endl;
    std::cout << "\nVector b:\n" << b << std::endl;

    // Resolver el sistema Ax = b.
    // Eigen::PartialPivLU es un buen solucionador de uso general para sistemas cuadrados.
    // Es robusto y numéricamente estable.
    Eigen::VectorXd x = A.partialPivLu().solve(b);

    std::cout << "\nSoluciones del sistema de ecuaciones (vector x):\n" << x << std::endl;

    // Opcional: Verificar la solución (A*x - b debe ser cercano a cero)
    std::cout << "\nVerificación (A*x - b):\n" << (A * x - b) << std::endl;

    return x;
}

int main() {
    // --- Ejemplo 1: Tu problema original (matriz 3x3) ---
    std::cout << "--- Ejemplo 1: Matriz 3x3 ---" << std::endl;
    Eigen::MatrixXd A_original(3, 3);
    A_original << 150, -100, 0,
                  -100, 150, -50,
                  0, -50, 50;

    Eigen::VectorXd b_original(3);
    b_original << 588.6,
                  686.7,
                  784.8;

    Eigen::VectorXd x_original = solveLinearSystemEigen(A_original, b_original);
    std::cout << "\n-------------------------------------\n" << std::endl;

    // --- Ejemplo 2: Una matriz 2x2 genérica ---
    std::cout << "--- Ejemplo 2: Matriz 2x2 genérica ---" << std::endl;
    Eigen::MatrixXd A_2x2(2, 2);
    A_2x2 << 4, 1,
             2, 3;

    Eigen::VectorXd b_2x2(2);
    b_2x2 << 6,
             8;

    // La solución esperada es x1 = 1, x2 = 2
    Eigen::VectorXd x_2x2 = solveLinearSystemEigen(A_2x2, b_2x2);
    std::cout << "\n-------------------------------------\n" << std::endl;

    // --- Ejemplo 3: Una matriz 4x4 genérica ---
    std::cout << "--- Ejemplo 3: Matriz 4x4 genérica ---" << std::endl;
    Eigen::MatrixXd A_4x4(4, 4);
    A_4x4 << 1, 2, 0, 0,
             0, 1, 2, 0,
             0, 0, 1, 2,
             0, 0, 0, 1;

    Eigen::VectorXd b_4x4(4);
    b_4x4 << 10,
             10,
             10,
             10;

    // La solución esperada es x4=10, x3=-10, x2=30, x1=-50
    Eigen::VectorXd x_4x4 = solveLinearSystemEigen(A_4x4, b_4x4);
    std::cout << "\n-------------------------------------\n" << std::endl;

    // --- Ejemplo 4: Caso de error (matriz no cuadrada) ---
    std::cout << "--- Ejemplo 4: Matriz no cuadrada (ERROR) ---" << std::endl;
    Eigen::MatrixXd A_non_square(2, 3); // 2 filas, 3 columnas
    A_non_square << 1, 2, 3,
                    4, 5, 6;
    Eigen::VectorXd b_error(2);
    b_error << 1, 2;
    Eigen::VectorXd x_error = solveLinearSystemEigen(A_non_square, b_error);
    if (x_error.size() == 0) {
        std::cout << "Manejo de error detectado para matriz no cuadrada." << std::endl;
    }
    std::cout << "\n-------------------------------------\n" << std::endl;

    // --- Ejemplo 5: Caso de error (tamaño de b no coincide) ---
    std::cout << "--- Ejemplo 5: Tamaño de b no coincide (ERROR) ---" << std::endl;
    Eigen::MatrixXd A_mismatch(3, 3);
    A_mismatch << 1, 2, 3,
                  4, 5, 6,
                  7, 8, 9;
    Eigen::VectorXd b_mismatch(2); // Debería ser 3
    b_mismatch << 1, 2;
    Eigen::VectorXd x_mismatch = solveLinearSystemEigen(A_mismatch, b_mismatch);
    if (x_mismatch.size() == 0) {
        std::cout << "Manejo de error detectado para tamaño de vector b incorrecto." << std::endl;
    }
    std::cout << "\n-------------------------------------\n" << std::endl;

    return 0;
}

/*
#include <iostream>
#include <Eigen/Dense> // Necesitas incluir este encabezado para la mayoría de las operaciones de Eigen

int main() {
    // 1. Definir la matriz A y el vector b

    // Matriz A (por ejemplo, una matriz 3x3)
    // Puedes inicializarla directamente o llenarla con datos.
    Eigen::MatrixXd A(3, 3);
    A << 3, -1, 1,
         1,  2, 0,
         0,  1, 4;

    // Vector b (por ejemplo, un vector 3x1)
    Eigen::VectorXd b(3);
    b << 6,
         3,
         11;

    std::cout << "Matriz A:\n" << A << std::endl;
    std::cout << "\nVector b:\n" << b << std::endl;

    // 2. Resolver el sistema Ax = b

    // Eigen ofrece varias formas de resolver sistemas lineales,
    // dependiendo de las propiedades de la matriz A (simétrica, positiva definida, etc.)
    // y de si necesitas más rendimiento o robustez.

    // Opción 1: Usando .solve() con una descomposición (recomendado para la mayoría de los casos)
    // Para matrices generales (no necesariamente simétricas o definidas positivas),
    // la descomposición LU es una buena opción por defecto.
    // Otras opciones incluyen HouseholderQR, ColPivHouseholderQR, FullPivLU, etc.
    // FullPivLU es la más robusta (maneja rangos deficientes), pero también la más lenta.
    // ColPivHouseholderQR es un buen equilibrio entre velocidad y robustez para matrices generales.

    Eigen::VectorXd x = A.colPivHouseholderQr().solve(b);

    std::cout << "\nSolución x (usando ColPivHouseholderQR):\n" << x << std::endl;

    // 3. Verificar la solución (opcional, pero buena práctica)
    // Puedes calcular Ax y ver si es aproximadamente igual a b.
    Eigen::VectorXd Ax_calculated = A * x;
    std::cout << "\nVerificación: A * x = \n" << Ax_calculated << std::endl;
    std::cout << "Diferencia ||A*x - b|| = " << (Ax_calculated - b).norm() << std::endl;

    // Si la matriz A es singular o el sistema no tiene una solución única,
    // .solve() intentará encontrar una solución de mínimos cuadrados.
    // Puedes verificar si la solución es "buena" inspeccionando la norma de la diferencia.
    // Un valor muy pequeño indica una buena solución.

    return 0;
}*/