#include "matrix_utils.h"

int main(void){

    std::vector<double> A(3*3,0.0);
    std::vector<double> C;
    fill_matrix_random(A,3,3,1);
    matrix_printer(A,3,3);

    std::cout << "----------\n";

    matrix_pow(A,C,3,2);
    matrix_printer(C,3,3);

    std::cout << "----------\n" << matrix_is_idempotent(A,3,2,1e-10);


    return 0;
}