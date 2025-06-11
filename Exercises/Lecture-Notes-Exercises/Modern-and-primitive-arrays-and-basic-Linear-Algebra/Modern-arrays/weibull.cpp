#include "functions_arrays.h"
#include <fstream>

int main(int argc, char **argv){
    int N = std::stod(argv[1]);
    double shape = std::stod(argv[2]);
    double scale = std::stod(argv[3]);
    int seed = std::stoi(argv[4]);
    double delta = std::stod(argv[5]);

    std::vector<double> u = weibull_vector(N,shape,scale,seed);
    std::vector<double> v = dbl_counter_histogram(u,delta);

    
    std::ofstream file("histogram.txt");

    file << "-------------------------------------\n";

    for (int ii{0}; ii < v.size()/2; ii++){
        file << v[ii*2] << "|";

        for (int kk{0}; kk<v[ii*2+1]; kk++){
            file << "*";
        }

        file << "\n";
    }

    file.close();

    


    return 0;
}