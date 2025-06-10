#include <vector>
#include <iostream>
#include <string>

//Declaration of the function
double fvector (std::vector<double>& data);

int main(int argc , char **argv)
{
    // declare the vector
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);
    std::vector<double> data; 

    // read the size from the command line
    const int N = std::stoi(argv[1]); 

    // resize the vector
    data.resize(N, 0);

    // initialize the data
    for(int ii = 0; ii < N; ii++) {
        data[ii] = ii;
    }

    double suma = fvector (data);
    std::cout << suma/N << "\n";

    return 0;
}

//Implementation of the function
double fvector (std::vector<double>& data){ 

    // compute the average
    double suma = 0.0;
    for(int ii = 0; ii < N; ii++) {
        suma = suma + data[ii];
    }
    return suma;

}