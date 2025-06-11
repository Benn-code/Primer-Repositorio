#include "matrix_utils.h"

int main(void){

    std::vector<double> M(4*4);
    std::vector<double> Z;
    fill_matrix_random(M,4,4,1);
    matrix_multiply_AB(M,M,Z,4,4,4,4);

    matrix_printer(M,4,4);
    std::cout << "----------------\n";
    matrix_printer(Z,4,4);
    
    std::cout << "----------------\n" << matrix_is_inverse(M,M,4,1e-10);

    return 0;
}