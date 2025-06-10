#include <iostream>
#include <string>
#include <algorithm> //necesario para std::reverse

//function declaration
bool isPalindrome(int numero);

int main(int argc, char **argv){
    if (argc != 2) { // Validar de los datos de entrada
        std::cerr << "The program requires one input.\n"
                     "Use it to indicate the number which you want to sum the digits.\n"
                     "Example: " << argv[0] << " <num> \n";
        return 1;
    }    
    long int o_number = std::stol(argv[1]);
    if (isPalindrome (o_number) == true) { 
        std::cout << o_number << " is a palindrome.\n";
    } else {
        std::cout << o_number << " is not a palindrome.\n";
    }

    return 0;
}


// function implementation
bool isPalindrome(int numero){
    std::string strNumero = std::to_string(numero);
    std::string strNumeroInvertido = strNumero;
    std::reverse(strNumeroInvertido.begin(), strNumeroInvertido.end());
    return strNumero == strNumeroInvertido;
}