/*
Aproximación de pi mediante la fórmula de Bailey-Borwein-Plouffe (BBP)
pi = SUMA(k=0, infinito) [1/(16^k) * (4/(8k+1) - 2/(8k+4) - 1/(8k+5) - 1/(8k+6))]
La función pi_aprox calcula la aproximación de pi usando los primeros n términos de la serie BBP en una función llamada pi_aprox. 
La función main imprime n,
retorna el valor de pi_aprox(n)
hace un loop que varía n entre 1 y 20,
llama a pi_aprox(n) y calcula la diferencia relativa entre la aproximación y el valor real de pi (M_PI).
*/

#include <iostream> 
#include <cmath>    // Para std::pow (potencia), M_PI (valor de pi), std::abs (valor absoluto)
#include <iomanip>  // Para manipular la salida (precisión, notación científica)

//Declaración de la función pi_aprox.  
double pi_aprox(int n);

int main(void) {
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);

    for (int n = 1; n <= 20; ++n) {
        double pi_calculado = pi_aprox(n);
        double diferencia_relativa = std::abs(1.0 - (pi_calculado / M_PI));
        std::cout << "n = " << n
                  << ", pi_aprox(n) = " << pi_calculado
                  << ", diferencia relativa = " << diferencia_relativa << std::endl;
    }
    return 0;
}

/*Implementación de la función pi_aprox. La función recibe enteros (int) y devuelve un número real (double). 
Se decide usar double sobre float (ambos para reales) porque generalmente ocupa 8 bytes de memoria, pero
proporciona alrededor de 15-16 dígitos decimales de precisión.
*/
double pi_aprox(int n) {
    double aproximacion = 0.0; // Variable para acumular la suma 
    for (int k = 0; k <= n; ++k) { // Bucle para sumar los términos desde k=0 hasta k=n
        double termino = (1.0 / pow(16, k)) *
                         (4.0 / (8 * k + 1) -
                          2.0 / (8 * k + 4) -
                          1.0 / (8 * k + 5) -
                          1.0 / (8 * k + 6));
        aproximacion += termino;
    }
    return aproximacion;
}