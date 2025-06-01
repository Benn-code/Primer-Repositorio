#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

bool isprime(long n);

int main(void) {
    int n_max = 100;
    int count = 0;
    long ii = 2;

    std::ofstream outfile("twin_primes_data.txt");

    if (outfile.is_open()) {
        outfile << "n,norma" << std::endl; // Escribir encabezado
        while (count < n_max) {
            if (isprime(ii) && isprime(ii + 2)) {
                count++;
                long p = ii;
                double norma = std::sqrt(std::pow(p, 2) + std::pow(p+2, 2) );
                outfile << count << "," << std::fixed << std::setprecision(6) << norma << std::endl;
            }
            ii++;
        }
        outfile.close();
        std::cout << "Los datos se han guardado en el archivo twin_primes_data.txt" << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo para escritura." << std::endl;
        return 1;
    }

    return 0;
}

bool isprime(long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}