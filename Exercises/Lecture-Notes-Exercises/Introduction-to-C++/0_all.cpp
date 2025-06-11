//Verifica si un número es par o impar (retorna true si es par)
bool isEven(int num) {
    return (num % 2 == 0);
}


//Verifica si un número es divisible por otros dos simultáneamente (returna true si es divisible por ambos)
bool isDivisibleByBoth(int n, int a, int b){
    return (n%a == 0 && n%b == 0);
}


// Verifica si un número es un palíndromo
bool isPalindrome(int numero){
    std::string strNumero = std::to_string(numero);
    std::string strNumeroInvertido = strNumero;
    std::reverse(strNumeroInvertido.begin(), strNumeroInvertido.end());
    return strNumero == strNumeroInvertido;
}


//Verifica si un número es primo
bool isprime(long n) {
    // Validación del rango
    if (n <= 1){
        std::cerr << "Out of range number: " << n << "\n";
        return false;
    }
    // suponer que es primo
    bool flag = true; 

    // Casos especiales
    if (n == 2){
        return true;
    }
    if (n % 2 == 0){
        return false;
    }

    // Solo necesitamos verificar divisores impares hasta la raíz cuadrada
    for (long ii = 3; ii * ii <= n; ii += 2) { // 'ii*ii <= n' es más robusto que 'ii <= std::sqrt(n)+1' para enteros grandes
        if (n % ii == 0) { // ii is divisor
            return false; // No es primo, salimos inmediatamente
        }
    }

    return flag;
}


//Cálculo del promedio de dos números
double average(double a, double b){
    return (a+b)/2;
}

//Calcula el Máximo Común Divisor (solo desde c++ 17)
double gcd (int num1, int num2){
    double result_gcd = std::gcd(num1, num2);
    return result_gcd;
}


//Suma armónica hasta un límite
double harmonic_sum (int limit){

       if (limit <= 0) {
        std::cerr << "The limit must be > 0 .\n";
        return 1;
    }

    double harmonic_sum = 0.0;
    for (int ii = 1 ; ii <= limit ; ii++){
        harmonic_sum += 1.0 / ii;
        }
    return harmonic_sum;
}


//Suma de los múltiplos de dos números en un rango
long int sum_of_the_multiples(int vmin, int vmax, int a, int b){
    if (vmax < vmin) {
        std::cerr << "The upper limit (vmax) must be greater than or equal to the lower limit (vmin).\n";
        return 1;
    }
    if (a == 0 || b == 0) {
    std::cerr << "Multiplers cannot be zero.\n";
    return 1;
    }
    long int Sum = 0;
    for (int ii = vmin; ii <= vmax; ii++){
        if (ii % a == 0 || ii % b == 0){
            Sum += ii;
        }
    }
    return Sum;
}


//Suma de los dígitos de un número
long int sum_of_the_digits(long int number){
    
    if (number < 0){
        number = -number;
    }
    long sum_of_digits = 0;
    if (number == 0) {
        sum_of_digits = 0; 
    } else {
        while (number > 0) {
            int digit = number % 10;  // Obtiene el último dígito (ej. 123 % 10 = 3)
            sum_of_digits += digit;   // Lo suma
            number /= 10;             // Elimina el último dígito (ej. 123 / 10 = 12)
        }
    }
    return sum_of_digits;
}





