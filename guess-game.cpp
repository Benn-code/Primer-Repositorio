/*
Juego de adivinar un número
Tener un número 
Preguntar al usuario un número
Informar si lo adivinó o no
*/
#include <iostream>

int main(void) {
    const int NUM = 10;
    int guessed_number;
    std::cout <<"Adivina un número entre 1 y 100:\n";
    std::cin >> guessed_number;

if (guessed_number == NUM) {
    std::cout <<"Muy bien, ¡era ese!\n";
} else if (guessed_number > NUM) {
    std::cout <<"Te pasaste\n";
}    else { // es menor, no es necesario ponerlo, pues es la única posibilidad restante
    std::cout <<"Te falta\n"; 
}
    return 0;
}