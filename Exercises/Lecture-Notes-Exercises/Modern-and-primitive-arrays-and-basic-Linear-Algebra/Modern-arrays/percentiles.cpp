#include "functions-arrays.h"
#include <fstream>
#include <string>

int main(void){

    std::ifstream file("RV.txt");

    std::vector<double> x,y;
    double xi,yi;

    while (file >> xi >> yi) {
        x.push_back(xi);
        y.push_back(yi);
    }

    std::cout << x[0] << "\n";

    file.close();


    std::cout << "MEAN T: " << p_norm(y,1.0)/y.size() << "\n"
            << "MEDIAN T: " << median(y) << "\n"
            << "P25: " << percentil(y,25) << "\n"
            << "P50: " << percentil(y,50) << "\n"
            << "P75: " << percentil(y,75) << "\n"
            << "MaxVal: " << y[argmax(y)] << "\n"
            << "MinVal: " << y[argmin(y)] << "\n"
            << "------------------------\n";

     // set the vector
    std::vector<double> data;
    data.resize(10);
    
    // fill the vector
    fill_randomly(data);
    
    // print the vector
    v_printer(data);
    std::cout << "------------------------\n";

    auto rng = std::default_random_engine {};
    std::shuffle(data.begin(), data.end(), rng);
    v_printer(data);
    std::cout << "------------------------\n";

    return 0;
}