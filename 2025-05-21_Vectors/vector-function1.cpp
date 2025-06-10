#include <vector>
#include <iostream>
#include <string>

//Declarations
double average(const std::vector<double> & x);
void llenar (;

int main(int argc , char **argv){
    // read the size from the command line
    const int N = std::stoi(argv[1]);

    // declare the vector
    std::vector<double> data;
    
    // resize the vector
    std::cout << "Pidiendo memoria ...\n";
    data.resize(N, 0); 
    
    // initialize the data
    //send that to fill the vector
    std::vector<double>& data = llenar (N);

    // compute the average
    std::cout << "Calculando promedio ...\n";
    double avg = average(data);
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    std::cout << avg << "\n";

    return 0;
}
double llenar (int N){

    std::cout << "Iniciando datos ...\n";
    for(int ii = 0; ii < N; ii++) {
        data[ii] = ii;
    }
    return std::vector<double> & x data[ii];
}

double average(const std::vector<double> & x){
    double suma = 0.0;
    for(int ii = 0; ii < x.size(); ii++) {
        suma = suma + x[ii];
    }
    return suma/x.size();
}