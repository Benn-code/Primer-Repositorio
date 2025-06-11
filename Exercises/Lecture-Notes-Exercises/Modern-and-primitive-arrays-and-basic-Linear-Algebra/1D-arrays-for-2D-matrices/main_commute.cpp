#include "matrix_utils.h"

int main(void){

    std::vector<double> M(4*4);
    std::vector<double> H(4*4);
    std::vector<double> Z;
    fill_matrix_random(M,4,4,1);
    fill_matrix_random(H,4,4,2);
    matrix_pow(M,Z,4,10);

    matrix_printer(M,4,4);
    std::cout << "----------------\n";
    matrix_printer(Z,4,4);
    std::cout << "----------------\n";
    matrix_printer(H,4,4);
    
    std::cout << "----------------\n" << matrix_commute(M,Z,4,1e-10) << "\n" << matrix_commute(M,H,4,1e-10);

    return 0;
}