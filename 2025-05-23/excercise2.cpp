#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

int main () {
// Create a vector
std::vector<int> numbers = {2, 3, 4, 5, 6};
std::cout << (&numbers[0]) << "\n";
//Hasta aquí hace la primera parte de crear el array, meterle los números pedidos e imprimir 
//el primero, falta meterle el 10 al final

//auto print = [](double x){ std::cout << x << "\n"; };
//std::for_each(numbers.begin(), numbers.end(), print);

// Add elements
numbers.push_back(10);

auto print2 = [](double x){ std::cout << x << "\n"; };
std::for_each(numbers.begin(), numbers.end(), print2);

// Get size
size_t size = numbers.size(); // Returns 6

// Access with bounds checking
int safe_access = numbers.at(2); // Throws exception for invalid index
}