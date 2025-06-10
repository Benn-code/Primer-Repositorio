/*"Write a program that prints the number of primes less than n for n between 2 and 200. Plot it using either gnuplot or matplotlib. 
Este programa
*/
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

// Declaración
bool isprime(long n);

int main(int argc, char **argv){
    if (argc != 3) { // Validar de los datos de entrada
        std::cerr << "The program requires two inputs.\n"
                     "Use the first to indicate the lower limit and the second to indicate the upper limit.\n"
                     "Example: " << argv[0] << " <vmin> <vmax>\n";
        return 1;
    }    

    // Convertir los argumentos de entrada a enteros y válidar el rango
    int vmin = std::stoi(argv[1]); //Límite inferior
    int vmax = std::stoi(argv[2]); //Límite superior
    if (vmin <= 1) {
        std::cerr << "Out of range number: " << vmin << ".\n The lower limit must be >= 2\n";
        return 1;
    }
    if (vmax < vmin) {
        std::cerr << "The upper limit (vmax) must be greater than or equal to the lower limit (vmin).\n";
        return 1;
    }

    
    //Evaluar los primos en el rango [vmin, vmax] e imprimirlos en terminal
        /*for(int ii = vmin; ii <= vmax; ++ii) {
            if (isprime(ii) == true) {
            std::cout << ii << "\n";
            }
        }
        */

   // Guardar los primos en un archivo
        /*std::ostringstream oss; // Crea un objeto ostringstream
        oss << "primes-between[" << vmin << "-" << vmax << "].txt"; // Escribe al stringstream
        std::string filename = oss.str(); // Obtiene el string final del stringstream
        */
    std::string filename = "primes-between[" + std::to_string(vmin) + "-" + std::to_string(vmax) + "].txt";
    std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filename << " for writing.\n";
            return 1;
        }
        int n = 0;
        for(int ii = vmin; ii <= vmax; ++ii) {
            if (isprime(ii) == true) {
            n = n + 1; // Contador de primos
            file << n << " "<< ii << " " << std::endl;
            }
        }
    file.close();
    std::cout << "Primes saved to " << filename << "\n"; // Confirmación para el usuario
    
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