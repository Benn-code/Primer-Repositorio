#include "matrix_utils.h"

int main(void){

    std::vector<double> A(4*4,0.0);
    std::vector<double> B(4*4,0.0);
    std::vector<double> C;

    fill_matrix_random(A,4,4,2);
    fill_matrix_random(B,4,4,1);
    
    matrix_printer(A,4,4);
    std::cout << "----------\n";
    matrix_printer(B,4,4);
    std::cout << "----------\n";

    matrix_multiply_AB(A,B,C,4,4,4,4);
    matrix_printer(C,4,4);

    return 0;
}