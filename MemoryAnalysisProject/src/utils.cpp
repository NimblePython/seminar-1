#include "../include/utils.h"
#include "../include/data.h"
#include <iostream>

// Функция быстрого возведения в степень (алгоритм с аккумулятором)
int power(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

// Работа с глобальными переменными
void manipulate_globals() {
    std::cout << "Manipulating global variable...\n";
    global_var += 5;
    std::cout << "Global variable after manipulation: " << global_var << "\n";
}

// Инициализация статической переменной
void initialize_static_variable() {
    static int static_var = 100;
    std::cout << "Static variable initialized to: " << static_var << "\n";
    static_var += 10;
    std::cout << "Static variable after modification: " << static_var << "\n";
}