/*"Write a program that reads a number from the command line and prints the sum of squares less than that number. Use it to plot the data.".
This program...
*/

#include <iostream>
#include <string>
#include <fstream>

bool sum_of_the_squares(long int number);

int main(int argc, char **argv){
    if (argc != 2) { // Validar de los datos de entrada
        std::cerr << "The program requires one input.\n"
                     "Use it to indicate the number which you want to sum of the squares less than it.\n"
                     "Example: " << argv[0] << " <num> \n";
        return 1;
    }   
    long int number = std::stol(argv[1]); // Convertir el argumento de entrada a entero
    if (number <= 0) {
        std::cerr << "The number must be greater than 0.\n";
        return 1;
    }
    sum_of_the_squares(number);
    
    return 0;
}

bool sum_of_the_squares(long int number){
std::string filename = "Squares less than" + std::to_string(number) + ".txt";
    std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filename << " for writing.\n";
            return 1;
        }
        int sum= 0;
        for(int ii = 0; ii <= number; ++ii) { 
            sum += ii*ii; // Suma de los cuadrados
            file << ii << " "<< sum << "\n";;
            }
    file.close();
    std::cout << "Squares saved to " << filename << "\n";
    return true; 
}