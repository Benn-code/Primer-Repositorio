/*A palindromic number reads the same both ways. 
The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>
#include <string>
#include <algorithm>

//function declaration
bool esPalindromo(int numero); 

int main(void) {
    int palindromoMasGrande = 0;
    int x = 0; int y = 0;
    // Aquí vendrían tus bucles anidados para los números de 3 dígitos
    for (int i = 100; i <= 999; ++i) {
        for (int j = 100; j <= 999; ++j) {
            int producto = i * j;
            if (esPalindromo(producto)== true && producto>=palindromoMasGrande){ 
                palindromoMasGrande = producto;
                x = i; y = j;
            }
        }
    }
    std::cout << "The largest palindrome made from the product of two 3-digit numbers is " << palindromoMasGrande 
    << " = " << x << " * " << y <<std::endl;
    return 0;
}

// function implementation
bool esPalindromo(int numero){
    std::string strNumero = std::to_string(numero);
    std::string strNumeroInvertido = strNumero;
    std::reverse(strNumeroInvertido.begin(), strNumeroInvertido.end());
    return strNumero == strNumeroInvertido;
}