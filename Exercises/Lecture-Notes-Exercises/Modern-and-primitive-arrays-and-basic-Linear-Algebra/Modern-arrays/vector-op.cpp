#include "functions_arrays.h"

int main(int argc , char **argv){

    std::vector<double> u={1,2,-10,3};
    std::vector<double> v={1,0,0,2};
    
    std::cout.precision(16);

    std::cout << vector_norm(v) << "\n";
    std::cout << std::inner_product(v.begin(),v.end(),u.begin(),0) << "\n";


    std::vector<double> derivative=poly_deriv(u);
    for ( int jj = 0; jj < derivative.size(); jj++){
        std::cout << derivative[jj] << "\n";
    }


    auto minit = std::min_element(u.begin(),u.end());
    std::cout << *minit << "\t" << argmin(u) << "\n";
 
    auto maxit = std::max_element(u.begin(),u.end());
    std::cout << *maxit << "\t" << argmax(u) << "\n";

    std::cout << p_norm(v,3) << "\n";

    return 0;
}