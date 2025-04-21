/*
Juego de adivinar un número
Tener un número 
Preguntar al usuario un número
Informar si lo adivinó o no
*/
#include <iostream>

// declaracion
void play(void);

int main(void) {
    play();

    return 0;
}

// implementación
void play(void)
{
    const int NUM = 10;
    int guessed_number = NUM/2;
    const int MIN = 0;
    const int MAX = 100;

    while(guessed_number != NUM) {
    std::cout <<"Adivina un número entre 1 y 100:\n";
    std::cin >> guessed_number;
    std::cout <<"Escribiste: " << guessed_number <<"\n";

    //Validación del rango
    if (guessed_number <= MIN or guessed_number > MAX){
        std::cout <<"Eso nisiquiera está dentro del rango, adiós.\n";
        break;
    }
    if (guessed_number == NUM) {
        std::cout <<"Muy bien, ¡era ese!\n";
     //Con el while, aquí habría el break en caso de acertar;
    } else if (guessed_number > NUM) {
    std::cout <<"Te pasaste\n";
    }      else { // es menor, no es necesario ponerlo, pues es la única posibilidad restante
    std::cout <<"Te falta\n"; }
    }
}