#include <iostream>
#include <cmath>
#include <string>

#include "prime_utils.h"

int main(int argc, char **argv){
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <numero>\n" << "El programa devuelve el factor primo más grande\n";
        return 1;
    }
     int num = std::stoi(argv[1]);
     if (num  <= 1) {
        std::cerr << "Número fuera de rango: " << num << "\n";
        return false; 
        break;
    }

if (isprime(num) == true) {
    std::cout << "El factor primo más grande de " << num << " es " << num << "\n"; 
} else {
    int variacion = num;
    int largestPrimeFactor = 1;

    // Dividir por 2
    while (variacion % 2 == 0) {
        largestPrimeFactor = 2;
        variacion /= 2;
    }

    // Iterar sobre impares hasta la raíz cuadrada
    for (long x = 3; x <= sqrt(variacion); x += 2) {
        while (variacion % x == 0) {
            largestPrimeFactor = x;
            variacion /= x;
        }
    }

    // Si lo que queda de variacion es mayor que 1, podría ser el factor primo más grande
    if (variacion > 1) {
        if (isprime(variacion)) {
            largestPrimeFactor = variacion;
        } else {
            largestPrimeFactor = std::max(largestPrimeFactor, variacion);
        }
    }

    std::cout << "El factor primo más grande de " << num << " es " << largestPrimeFactor << "\n";
}

return 0;
}
