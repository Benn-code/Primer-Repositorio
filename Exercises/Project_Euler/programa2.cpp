/*Este programa recibe un número entero como argumento y calcula el factor primo más grande de ese número.
La función main se encarga de leer el número, verificar el rango y llamar a las funciones para luego imprimir el resultado
La función isprime se encarga de verificar si un número es primo o no.
La función largest_prime_factor se encarga de calcular el factor primo más grande
*/

#include <iostream>
#include <cmath>
#include <string>

//Declaración de las funciones
bool isprime(long n);
long largest_prime_factor (long n);

int main(int argc, char **argv){
    if (argc != 2) { // Esto comprueba si se ha pasado un argumento, en caso de que no, se indica al usuario como usar el programa
        std::cerr << "Uso: " << argv[0] << " <numero>\n";
        return 1;
    }
    long num = std::stol(argv[1]);
    if (num < 2) { 
        std::cerr << "Out of range number: " << num << "\n"; //Se evita llamar innecesariamente a isprime
            return 1;
    }
    if (isprime(num) == true) {
        std::cout << num << "\n";
    } else {
        long result_prime_factor = largest_prime_factor (num);
        std::cout << result_prime_factor << "\n";
    }

    return 0;
}


// implementación de isprime
bool isprime(long n) {
    if (n <= 1) {
        std::cerr << "Out of range number: " << n << "\n";
        return false;
    }
    bool flag = true;
    if (n == 2) {
        return true;
    }
    for (long ii = 2; ii <= std::sqrt(n) + 1; ii++) {
        if (n%ii == 0) { // ii is divisor
            flag = false;
            break; // end, at least one divisor
        }
    }
    return flag;
}

//Implementación de la función largest_prime_factor
/*Funciona como cuando descomponemos un número a mano.
*/

long largest_prime_factor (long n){

    long variacion = n;
    long largestPrimeFactor = 0;

    // Dividir por 2 mientras se pueda
    while (variacion % 2 == 0) {
        largestPrimeFactor = 2;
        variacion /= 2;
    }

    // Iterar sobre impares a partir de 3 para no usar todos los números
    for (long x = 3; x <= sqrt(variacion); x += 2) {
        while (variacion % x == 0) { //Dividir por x mientras se pueda
            largestPrimeFactor = x;
            variacion /= x;
        }
    }

    // Si lo que queda de variacion es mayor que 1 y es primo, ese sería el factor primo más grande
    if (variacion > 1 && isprime(variacion)) {
            largestPrimeFactor = variacion;
        }
     
    return largestPrimeFactor; // Ahora la función devuelve el resultado
}

