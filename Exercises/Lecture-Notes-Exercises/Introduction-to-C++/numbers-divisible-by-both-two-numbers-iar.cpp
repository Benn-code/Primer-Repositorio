/*"Write a program that prints the numbers between 5 and 223 which are divisible by both 3 and 7.
Print the numbers separated by a space, and a new line only at the end. 
Use the three types of classical loops (so your program must print the same three times)""
*/

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

//Declaration
bool isDivisibleByBoth(int n, int a, int b);

int main(int argc, char **argv){
    if (argc != 5) { // Validar de los datos de entrada
        std::cerr << "The program requires four inputs.\n"
                     "Use the first two values ​​to indicate the range" 
                     "and the remaining two to indicate the numbers by which you want to check that they are divisible simultaneously.\n"
                     "Example: " << argv[0] << " <vmin> <vmax> <divisor1> <divisor2> \n";
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
    std::cerr << "Error: Divisors cannot be zero. Please provide non-zero divisors.\n";
    return 1;
    }
    
    std::cout << "Los números divisibles por " << a << " y " << b << " en el rango" << "[" << vmin << "-" << vmax << "] son:\n";

    for (int ii = vmin ; ii <= vmax ; ii++){
        if (isDivisibleByBoth(ii, a, b)){
            std::cout << ii << " ";  
        }
    }
    std::cout << "\n";
   
    int min = vmin;
    while (min <= vmax){
        if (isDivisibleByBoth(min, a, b)){
            std::cout << min << " "; 
        }
        min ++;  
    } 
    std::cout << "\n";

    min = vmin;
    do  {
        if (isDivisibleByBoth(min, a, b)){
            std::cout << min << " "; 
        }
        min ++;
    } while(min <= vmax);
    std::cout << "\n";

    return 0;
}

//Implementation
bool isDivisibleByBoth(int n, int a, int b){
    return (n%a == 0 && n%b == 0);
}