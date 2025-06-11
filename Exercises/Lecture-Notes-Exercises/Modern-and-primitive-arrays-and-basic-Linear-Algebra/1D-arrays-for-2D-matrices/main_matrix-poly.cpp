#include "matrix_utils.h"

int main(void){

    std::vector<double> u={1,0,1};
    std::vector<double> C(2*2);
    std::vector<double> Z;
    
    fill_matrix_random(C,2,2,1);

    matrix_printer(C,2,2);
    std::cout << "\n";

    Z = matrix_polynomial(C,2,u);
    matrix_printer(Z,2,2);

    return 0;
}