/* Este programa recibe un entero y devuelve la suma de los primos menores o iguales a ese número. 
El programa contempla dos casos para la entrada:
    Si el número es menor a 2 muestra un mensaje de error.
    Si el número es mayor o igual a 2, se itera de dos en dos desde 3 hasta el número dado, sumando los primos encontrados.
La función main se encarga de leer el número, verificar el rango y calcular la suma de los primos menores o iguales.
La función isprime se encarga de verificar si un número es primo o no.
*/

#include <iostream>
#include <cmath>

//Declaración de la función isprime
bool isprime(long n);

int main(int argc, char **argv){ 
    if (argc != 2) { // Esto comprueba si se ha pasado un argumento, en caso de que no, se indica al usuario como usar el programa
        std::cerr << "Use: " << argv[0] << " <number>\n";
        return 1;
    }
    long num = std::stol(argv[1]); // Convierte el argumento a entero
    long suma = 0; 
        if (num < 2) { 
            std::cerr << "Out of range number: " << num << "\n"; //Se evita llamar innecesariamente a isprime
            return 1;
        }
        if (num >= 2) {
            suma = 2; //Esto inicializa la suma con 2 ya que no se incluye en la iteración por ser par    
            for(int ii = 3; ii <= num; ii += 2) { //Evaluar de dos en dos reduce los calculos necesarios a la mitad
                if (isprime(ii) == true) {
                suma += ii;    
                }
            }
        } 
    std::cout << suma << "\n";
    return 0;
}

// Implementación de isprime
bool isprime(long n) {
    // precondition checks
    // do something if n <= 1
    if (n <= 1) { //Esta verificación podría ser innecesaria porque se cubre en main, pero se deja para no modificar isprime
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


