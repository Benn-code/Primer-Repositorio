#include <iostream>
#include <cmath>
#include <string>

// declaration
bool isprime(long n);

int main(int argc, char **argv){

    int vmin = std::stoi(argv[1]);
    int vmax = std::stoi(argv[2]);

    for(int ii = vmin; ii <= vmax-4; ++ii) {
        if (isprime(ii) == true and isprime(ii+4) == true) {
            std::cout << "(" << ii << ", " << ii+4 << ") ";
        }
    }
    std::cout << "\n";

    return 0;
}

// implementación
bool isprime(long n) {
    // Validación del rango
    if (n <= 1){
        std::cerr << "Out of range number: " << n << "\n";
        return false;
    }
    // uponer que es primo
    bool flag = true; 

    // Casos especiales
    if (n == 2){
        return true;
    }
    if (n % 2 == 0){
        return false;
    }

    // Solo necesitamos verificar divisores impares hasta la raíz cuadrada
    for (long ii = 3; ii * ii <= n; ii += 2) { // 'ii*ii <= n' es más robusto que 'ii <= std::sqrt(n)+1' para enteros grandes
        if (n % ii == 0) { // ii is divisor
            return false; // No es primo, salimos inmediatamente
        }
    }

    return flag;
}