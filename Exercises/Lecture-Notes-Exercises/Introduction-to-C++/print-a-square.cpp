#include <iostream>
#include <string> // Necesario para std::stoi

int main(int argc, char **argv) {
    // 1. Validar la entrada desde la línea de comandos
    if (argc != 2) {
        std::cerr << "El programa imprime un cuadrado de asteriscos de <numero_positivo>x<numero_positivo>.\n"
                    "Uso: " << argv[0] << " <numero_positivo>\n";
        return 1; // Salir con código de error
    }

    // 2. Convertir el argumento a un número entero
    int size = std::stoi(argv[1]);

    // 3. Validar que el número sea positivo (y razonable)
    if (size <=0 || size >= 51) {
        std::cerr << "El número debe estar entre 1 y 50.\n";
        return 1;
    }

    // 4. Construir y imprimir el cuadrado
    // Bucle exterior para las filas
    for (int row = 0; row < size; ++row) {
        // Bucle interior para las columnas en cada fila
        for (int col = 0; col < size; ++col) {
            // Condición para imprimir un asterisco:
            // Si es la primera fila (row == 0)
            // O si es la última fila (row == size - 1)
            // O si es la primera columna (col == 0)
            // O si es la última columna (col == size - 1)
            if (row == 0 || row == size - 1 || col == 0 || col == size - 1) {
                std::cout << "*"; // Imprime un asterisco
            } else {
                std::cout << " "; // Imprime un espacio
            }
        }
        std::cout << "\n"; // Después de imprimir todas las columnas de una fila, salta de línea
    }

    return 0; // Salir con éxito
}