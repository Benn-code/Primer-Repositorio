#include "matrix_utils.h"

int main(void){

    std::vector<std::complex<double>> sigma1;
    std::vector<std::complex<double>> sigma2;
    std::vector<std::complex<double>> sigma3;
    std::vector<std::complex<double>> aux1;
    std::vector<std::complex<double>> aux2;
    std::vector<std::complex<double>> aux3;

    complex_fill_matrix_pauli_base(sigma1,sigma2,sigma3);



    general_matrix_multiply_AB(sigma1,sigma2,aux1,2,2,2,2);
    general_matrix_multiply_AB(sigma2,sigma1,aux2,2,2,2,2);

    general_matrix_substract(aux1,aux2,aux3);

    matrix_printer(aux3,2,2);
    std::cout << "\n";

    general_matrix_multiply_AB(sigma2,sigma3,aux1,2,2,2,2);
    general_matrix_multiply_AB(sigma3,sigma2,aux2,2,2,2,2);

    general_matrix_substract(aux1,aux2,aux3);

    matrix_printer(aux3,2,2);
    std::cout << "\n";


    return 0;
}