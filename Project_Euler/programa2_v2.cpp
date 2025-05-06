#include <iostream>
#include <cmath>
#include <string>

//Declaración de la función isprime
bool isprime(long n);

int main(int argc, char **argv){
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <numero>\n" << "El programa devuelve el factor primo más grande\n";
        return 1;
    }
    long num = std::stol(argv[1]);
     //if (num  <= 1) {
        //std::cerr << "Número fuera de rango: " << num << "\n";
    //}

if (isprime(num) == true) {
    std::cout << num << "\n"; 
} else {
    long variacion = num;
    long largestPrimeFactor = 0;

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

    std::cout << largestPrimeFactor << "\n";
}

return 0;
}


// implementation
bool isprime(long n) {
    // precondition checks
    // do something if n <= 1
    if (n <= 1) {
        std::cerr << "Out of range number: " << n << "\n";
        return false;
    }

    // suppose it is prime
    bool flag = true; 

    if (n == 2) {
        return true;
    }

    // find divisors
    for (long ii = 2; ii <= std::sqrt(n) + 1; ii++) {
        if (n%ii == 0) { // ii is divisor
            flag = false;
            break; // end, at least one divisor
        }
    }

    return flag;
}