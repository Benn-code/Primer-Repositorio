/*  Este programa recibe un número entero como argumento y calcula la serie de fibonacci hasta ese número.
Luego calcula la suma de los números impares de la serie mientras esta no genere un número mayor al argumento.
Si el argumento es menor a 2, se muestra un mensaje de error.
La función main se encarga de leer el número, verificar el rango, llamar a la función y luego imprimir el resultado.
*/

#include <iostream>
#include <cmath>

//Declaración de la función
long suma_fibonacci_impares(long n);

int main(int argc, char **argv){
    if (argc != 2) { // Esto comprueba si se ha pasado un argumento, en caso de que no, se indica al usuario como usar el programa
        std::cerr << "Use: " << argv[0] << " <number>\n";
        return 1;
    }
    long num = std::stol(argv[1]); 
    if (num < 2) { //Comprobación del rango
        std::cerr << "Out of range number: " << num << std::endl; 
        return 1;
    } else {
        long suma = suma_fibonacci_impares(num);
        std::cout << suma << std::endl;
    }
    return 0;
}

//Implementación de la función
long suma_fibonacci_impares(long n){
    long fib1 = 1;
    long fib2 = 1;
    long fib = 0;
    long suma_impares = 0;

    if (fib2 % 2 != 0 && fib2 <= n) {
        suma_impares += fib2;
    }

    while (fib < n) {
        fib = fib1 + fib2;
        if (fib > n) {
            break; // Se detiene si excede el límite
        }
        if (fib % 2 != 0) {
            suma_impares += fib;
        }
        fib1 = fib2;
        fib2 = fib;
    }
    return suma_impares;
}