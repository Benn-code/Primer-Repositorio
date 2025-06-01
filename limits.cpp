#include <iostream>
#include <limits>

int main() {
    std::cout << "--- Información de int ---" << std::endl;
    std::cout << "Mínimo: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "Máximo: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "Es con signo: " << std::numeric_limits<int>::is_signed << std::endl;
    std::cout << "Número de dígitos decimales de precisión: " << std::numeric_limits<int>::digits10 << std::endl;
    std::cout << std::endl;

    std::cout << "--- Información de long ---" << std::endl;
    std::cout << "Mínimo: " << std::numeric_limits<long>::min() << std::endl;
    std::cout << "Máximo: " << std::numeric_limits<long>::max() << std::endl;
    std::cout << "Es con signo: " << std::numeric_limits<long>::is_signed << std::endl;
    std::cout << "Número de dígitos decimales de precisión: " << std::numeric_limits<long>::digits10 << std::endl;
    std::cout << std::endl;

    std::cout << "--- Información de double ---" << std::endl;
    std::cout << "Mínimo positivo normalizado: " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "Máximo: " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "Valor negativo más pequeño: " << std::numeric_limits<double>::lowest() << std::endl;
    std::cout << "Mínimo positivo subnormal: " << std::numeric_limits<double>::denorm_min() << std::endl;
    std::cout << "Épsilon (diferencia entre 1 y el siguiente valor mayor): " << std::numeric_limits<double>::epsilon() << std::endl;
    std::cout << "Tiene representación subnormal: " << std::numeric_limits<double>::has_denorm << std::endl;
    std::cout << "Número de dígitos decimales de precisión: " << std::numeric_limits<double>::digits10 << std::endl;
    std::cout << std::endl;

    std::cout << "--- Información de char ---" << std::endl;
    std::cout << "Es con signo por defecto: " << std::numeric_limits<char>::is_signed << std::endl;
    std::cout << "Mínimo (como int): " << static_cast<int>(std::numeric_limits<char>::min()) << std::endl;
    std::cout << "Máximo (como int): " << static_cast<int>(std::numeric_limits<char>::max()) << std::endl;
    std::cout << std::endl;

    std::cout << "--- Información de signed char ---" << std::endl;
    std::cout << "Mínimo (como int): " << static_cast<int>(std::numeric_limits<signed char>::min()) << std::endl;
    std::cout << "Máximo (como int): " << static_cast<int>(std::numeric_limits<signed char>::max()) << std::endl;
    std::cout << std::endl;

    std::cout << "--- Información de unsigned char ---" << std::endl;
    std::cout << "Mínimo (como int): " << static_cast<int>(std::numeric_limits<unsigned char>::min()) << std::endl;
    std::cout << "Máximo (como int): " << static_cast<int>(std::numeric_limits<unsigned char>::max()) << std::endl;
    std::cout << std::endl;

    std::cout << "--- Información de float ---" << std::endl;
    std::cout << "Mínimo positivo normalizado: " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "Máximo: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "Valor negativo más pequeño: " << std::numeric_limits<float>::lowest() << std::endl;
    std::cout << "Mínimo positivo subnormal: " << std::numeric_limits<float>::denorm_min() << std::endl;
    std::cout << "Épsilon (diferencia entre 1 y el siguiente valor mayor): " << std::numeric_limits<float>::epsilon() << std::endl;
    std::cout << "Tiene representación subnormal: " << std::numeric_limits<float>::has_denorm << std::endl;
    std::cout << "Número de dígitos decimales de precisión: " << std::numeric_limits<float>::digits10 << std::endl;
    std::cout << std::endl;


    std::cout << "float lowest: " << std::numeric_limits <float>::lowest() << '\n';
    std::cout << "double max: " << std::numeric_limits <double>::max() << '\n';
    std::cout << "double min: " << std::numeric_limits <double>::min() << '\n';
    std::cout << "float min: " << std::numeric_limits <float>::min() << '\n';
    std::cout << "double lowest: " << std::numeric_limits <double>::lowest() << '\n';
    std::cout << "float max: " << std::numeric_limits <float>::max() << '\n';

    return 0;
}