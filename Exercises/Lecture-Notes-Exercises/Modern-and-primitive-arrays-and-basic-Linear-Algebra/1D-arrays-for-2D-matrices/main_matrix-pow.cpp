#include "matrix_utils.h"

int main(void){

    std::vector<double> A={1,2,3,4,5,6,7,8,9};
    std::vector<double> C;
    
    matrix_printer(A,3,3);
    std::cout << "----------\n";

    matrix_pow(A,C,3,2);
    matrix_printer(C,3,3);

    return 0;
}