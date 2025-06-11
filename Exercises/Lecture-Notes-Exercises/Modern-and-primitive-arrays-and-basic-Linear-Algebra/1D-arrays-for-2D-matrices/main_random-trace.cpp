#include "matrix_utils.h"

int main(void){

    std::vector<double> M(4*4,0.0);
    fill_matrix_random(M,4,4,1);

    matrix_printer(M,4,4);

    double trace{0};
    trace=matrix_trace(M,4);
    
    std::cout << trace;

    return 0;
}