/*Write a program that computes the harmonic sum until some limit. Write, in the main function some tests for it.
This program...
*/

#include <iostream>

double harmonic_sum (int limit);

int main(int argc, char **argv){
    if (argc != 2) { // Validar de los datos de entrada
        std::cerr << "The program requires one input.\n"
                     "Use it to indicate the limit of the harmonic sum.\n"
                     "Example: " << argv[0] << " <num> \n";
        return 1;
    }    

    // Convertir los argumentos de entrada a enteros y válidar el rango
    int limit = std::stoi(argv[1]); 
    
    std::cout << "The harmonic sum until " << limit << " is: " << harmonic_sum(limit) << "\n";
    return 0;
}

double harmonic_sum (int limit){

       if (limit <= 0) {
        std::cerr << "The limit must be > 0 .\n";
        return 1;
    }

    double harmonic_sum = 0.0;
    for (int ii = 1 ; ii <= limit ; ii++){
        harmonic_sum += 1.0 / ii;
        }
    return harmonic_sum;

}

