/* Este programa recibe un entero y devuelve la suma de los primos menores o iguales a ese número. 
El programa contempla tres casos para la entrada:
    Si el número es menor o igual a 1, se muestra un mensaje de error.
    Si el número es 2, se devuelve 2.
    Si el número es mayor que 2, se itera de dos en dos desde 3 hasta el número dado, sumando los primos encontrados.
La función principal se encarga de leer el número, verificar el rango y calcular la suma de los primos menores o iguales a él.
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
    long suma = 0; // Inicializa la suma con 2, ya que es el primer primo y es un caso especial
        for(int ii = 2; ii<= num; ii++) {
             if (isprime(ii) == true) {
             suma += ii;    
                }
            }
            std::cout << suma << "\n";

        return 0;
    }

// implementation
bool isprime(long n) {

    if (n <= 1) {
        std::cerr << "Out of range number: " << n << "\n";
        return false;
        }  
    if (n == 2) {
        return true;
        }   
   
    // Suponer que es primo
    bool flag = true; 

    // find divisors
    for (long ii = 2; ii <= std::sqrt(n) + 1; ii++) {
        if (n%ii == 0) { // ii is divisor
            flag = false;
            break; // end, at least one divisor
        }
    }

    return flag;
}