#include "matrix_utils.h"

int main(void){

    std::vector<std::complex<double>> M={1,std::complex(1.0,1.0),1,1};
    std::vector<std::complex<double>> Z;
    complex_fill_matrix_identity(Z,2);

    matrix_printer(M,2,2);
    std::cout << "----------------\n";
    matrix_printer(Z,2,2);
    
    std::cout << "----------------\n" << complex_matrix_is_hermitian(M,2) 
        << "\n" << complex_matrix_is_hermitian(Z,2);

    return 0;
}