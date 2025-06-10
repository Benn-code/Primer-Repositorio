/*"Write a program that given a number, prints the sum of its digits".
This program...
*/

#include <iostream>

long int sum_of_the_digits(long int number);

int main(int argc, char **argv){
    if (argc != 2) { // Validar de los datos de entrada
        std::cerr << "The program requires one input.\n"
                     "Use it to indicate the number which you want to sum the digits.\n"
                     "Example: " << argv[0] << " <num> \n";
        return 1;
    }    
    long int o_number = std::stol(argv[1]); // Convertir el argumento de entrada a entero

    long int result = sum_of_the_digits (o_number);

    std::cout << "The sum of the digits of " << o_number << " is: \n" << result << "\n";

    return 0;
}

long int sum_of_the_digits(long int number){
    
    if (number < 0){
        number = -number;
    }
    long sum_of_digits = 0;
    if (number == 0) {
        sum_of_digits = 0; 
    } else {
        while (number > 0) {
            int digit = number % 10;  // Obtiene el último dígito (ej. 123 % 10 = 3)
            sum_of_digits += digit;   // Lo suma
            number /= 10;             // Elimina el último dígito (ej. 123 / 10 = 12)
        }
    }
    return sum_of_digits;
}

