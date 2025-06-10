/*"Write a program that computes the sum of the multiples of 3 and 5 in the range 1 <= x <= 1123."
This program...
*/

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

//Declaration
long int SumoftheMultiples(int vmin, int vmax, int a, int b);

int main(int argc, char **argv){
    if (argc != 5) { // Validar de los datos de entrada
        std::cerr << "The program requires four inputs.\n"
                     "Use the first two values to indicate the range" 
                     "and the remaining two to indicate the numbers by which you want to sum the products.\n"
                     "Example: " << argv[0] << " <vmin> <vmax> <num1> <num2> \n";
        return 1;
    }    

    // Convertir los argumentos de entrada a enteros y válidar el rango
    int vmin = std::stoi(argv[1]); //Límite inferior
    int vmax = std::stoi(argv[2]); //Límite superior
    int a = std::stoi(argv[3]); // Divisor 1
    int b = std::stoi(argv[4]); //Divisor 2
    
    if (vmax < vmin) {
        std::cerr << "The upper limit (vmax) must be greater than or equal to the lower limit (vmin).\n";
        return 1;
    }
    if (a == 0 || b == 0) {
    std::cerr << "Multiplers cannot be zero.\n";
    return 1;
    }
    
    long int Result = SumoftheMultiples(vmin, vmax, a, b);
    
    std::cout << "The sum of the multiples of " << a << " and " << b  << " in the range [" << vmin << "-" << vmax << "] are:\n";
    std::cout << Result << "\n";
   
    return 0;
}

//Implementation
long int SumoftheMultiples(int vmin, int vmax, int a, int b){
    long int Sum = 0;
    for (int ii = vmin; ii <= vmax; ii++){
        if (ii % a == 0 || ii % b == 0){
            Sum += ii;
        }
    }
    return Sum;
}