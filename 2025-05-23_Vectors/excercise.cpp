#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

int main()
{
// Allocate memory for 10 integers
int * dynamic_array = new int[5];
// todo: check if memory was actually allocated

// Use the array
dynamic_array[0] = 2;
dynamic_array[1] = 3;
dynamic_array[2] = 4;
dynamic_array[3] = 5;
dynamic_array[4] = 6;
//std::for_each(dynamic_array.begin(), dynamic_array.end(), print);

//print
std::cout << (dynamic_array[0]) << "\n";

// IMPORTANT: Must deallocate manually
delete[] dynamic_array;

//Add new
dynamic_array = new int [0] 
//dynamic_array.push_back(10);

}