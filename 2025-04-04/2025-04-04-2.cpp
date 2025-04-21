#include<iostream>
#include<string>

int main(void)
{
    std::string name;
    std::string age;
    std::cout <<"Hola, ¿cuál es tu nombre?\n";
    // std::cin >> name; // lee hasta el primer espacio 
    std::getline(std::cin, name);
    std::cout << "¡Hola, " <<name << "! ¿cuántos años tienes?\n";
    std::getline(std::cin, age);
    std::cout << "Genial.\n";

    return 0;
}