#include <iostream>
#include <string>
#include <iomanip> // Para setw

int neuman_string_int_square(int x, int y);

int main(int argc, char **argv){ 


    if (argc != 3) { 
        std::cerr << "Use: " << argv[0] << " <number> <number>\n";
        return 1;
    }
    int valor = std::stoi(argv[1]);
    int steps = std::stoi(argv[2]);
    int result = neuman_string_int_square (valor,steps);
    std::cout << result << '\n';
    return 0;
}

int neuman_string_int_square(int x, int y) {
    std::string current_number_str = std::to_string(x);

    /*if (current_number_str.length() != 4) {
        std::cerr << "Advertencia: El número inicial no tiene 4 dígitos. El comportamiento podría ser inesperado.\n";
    }
    */

    for (int ii = 0; ii < y; ++ii) {
        int squared = std::stoi(current_number_str) * std::stoi(current_number_str);
        std::string squared_str = std::to_string(squared);
        int len = squared_str.length();
        std::string center_digits = "";

        std::cout << "Iteración " << std::setw(3) << ii + 1 << ": Número = " << std::setw(8) << current_number_str
                  << ", Cuadrado = " << std::setw(16) << squared_str;

        if (len < 4) {
            center_digits = std::string(4 - len, '0') + squared_str; // Pad con ceros a la izquierda
        } else {
            int start = (len - 4) / 2;
            center_digits = squared_str.substr(start, 4);
        }

        current_number_str = center_digits;
        std::cout << ", Centro = " << center_digits << "\n";

        if (current_number_str.length() != 4) {
            std::cerr << "Advertencia en la iteración " << ii + 1 << ": El nuevo número no tiene 4 dígitos.\n";
        }
    }

    return std::stoi(current_number_str);
}

