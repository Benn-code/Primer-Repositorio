/* Este programa recibe un entero y devuelve la suma de los primos menores o iguales a ese número. 
El programa contempla tres casos para la entrada:
    Si el número es menor o igual a 1, se muestra un mensaje de error.
    Si el número es 2, se devuelve 2.
    Si el número es mayor que 2, se itera de dos en dos desde 3 hasta el número dado, sumando los primos encontrados.
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
    long suma = 2; // Inicializa la suma con 2, ya que es el primer primo y es un caso especial
        if (num <= 1) { //Comprobación del rango 
            std::cerr << "Out of range number: " << num << std::endl;
        } else if (num == 2) {
            std::cout << num << "\n";
            } else { 
                for(int ii = 3; ii <= num; ii += 2) { 
                if (isprime(ii) == true) {
                suma += ii;    
                }
                } 
             std::cout << suma << "\n";
            }

        return 0;
    }

// Implementación de isprime
bool isprime(long n) {
    /* En este caso no se requieren precondiciones, ya que la función main se encarga de verificar el rango del número.
    Sin embargo, se dejan como práctica defensiva (para no modificar la función isprime).

    Si se entrega un número menor o igual a dos, nisiquiera se usa la función isprime. 
    Mi idea de optimización del código está en que una vez se verifica que el número es mayor a 2,
    se puede iterar de dos en dos desde 3 (3,5,7,9,11,13...), ya que los números pares no son primos, 
    con eso se evita evaluar todos los números y se reduce el número de cálculos a la mitad. 
    Para ello es necesario iniciar el bucle for de main en 3 y la suma en 2 habiéndo dejado el dos como caso especial.
    (sino, tendría que inicializarlo en 2 y ya no podría iterar de dos en dos (2,4,6,8,10...), 
    o en 1, pero entonces si se itera de dos en dos se salta el dos (1,3,5,7,9...)
    y en ese caso no se puede inicializar la suma en dos porque si alguien pone un número <= 2 dará 2 siempre).
    
    Para verificar la reducción de tiempo en los cálculos se puede usar time ./a.out 
    La diferencia es poca, pero es más evidente cuando se usan números «grandes» como el de 749320
    */  
   
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



