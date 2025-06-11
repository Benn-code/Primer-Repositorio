#include "matrix_utils.h"

int main(void){

    std::vector<double> M(4*4);
    std::vector<double> Z(4*4);
    fill_matrix_identity(M,4);
    fill_matrix_random(Z,4,4,1);

    matrix_printer(M,4,4);
    std::cout << "----------------\n";
    matrix_printer(Z,4,4);
    std::cout << "----------------\n" << matrix_is_orthogonal(M,4,1e-10) << "\n" << matrix_is_orthogonal(Z,4,1e-10);

    return 0;
}