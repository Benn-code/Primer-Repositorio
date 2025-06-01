/* If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3,5,6 and 9.
The sum of these multiples is 23.
This program find the sum of all the multiples of 3 or 5 bellow a number readed from the console.
*/

#include <iostream>
#include <cmath>

// function declaration
long sum_multiples_3_5_bellow(long n);

int main(int argc, char **argv){ 
    if (argc != 2) { 
        std::cerr << "Use: " << argv[0] << " <number>\n";
        return 1;
    }
    long num = std::stol(argv[1]);
        if (num < 0) { 
        std::cerr << "Out of range number: " << num << "\n";
        return 1;
        } 
        if (0<=num && num<=3) { 
        std::cout << "The sum of all the multiples of 3 or 5 bellow " << num << " is: 0\n";
        return 0;
        }
    long result = sum_multiples_3_5_bellow(num);
        std::cout << "The sum of all the multiples of 3 or 5 bellow " << num << " is: " << result << "\n";
    return 0;
}

// implementation
long sum_multiples_3_5_bellow(long n){
    long sum = 0;
    
    for (long ii=3 ; ii < n ; ii++){
    if(ii%3 == 0){
        sum += ii;
    }
        else if (ii%5 == 0){
        sum += ii;
    }  
    } 
    return sum;
}