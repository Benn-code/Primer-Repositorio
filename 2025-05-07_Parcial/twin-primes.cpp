#include <iostream>
#include <cmath>

// Declaración de la función
bool isprime(long n);
void nth_twin_primes(int n); // La función solo imprime

// Implementación de la función principal (aunque el problema pide no escribir main)

int main(int argc, char **argv){ 
    if (argc != 2) { 
        std::cerr << "Use: " << argv[0] << " <number>\n";
        return 1;
    }
    int num = std::stoi(argv[1]);
        if (num < 0) { 
        std::cerr << "Out of range number: " << num << "\n";
        return 1;
        } 
    nth_twin_primes(num);
    return 0;
}


// Implementación de la función para encontrar la n-ésima pareja de primos gemelos
void nth_twin_primes(int n) {
    int count = 0;
    for (long ii = 2; count < n; ++ii) {
        if (isprime(ii) && isprime(ii + 2)) {
            count++;
            if (count == n) {
                std::cout << "(" << ii << ", " << ii + 2 << ")" << std::endl;
                break; // Detener la búsqueda una vez encontrada la n-ésima pareja
            }
        }
    }
    if (count < n) {
        std::cout << "No se encontraron " << n << " parejas de primos gemelos dentro del rango examinado." << std::endl;
    }
}

// Implementación de la función para verificar si un número es primo
bool isprime(long n) {
    if (n <= 1) {
        std::cerr << "Out of range number: " << n << std::endl;
        return false;
    }
    bool flag = true;
    if (n == 2) {
        return true;
    }
    for (long ii = 2; ii <= std::sqrt(n); ++ii) {
        if (n % ii == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}