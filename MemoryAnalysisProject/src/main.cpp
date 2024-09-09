#include <iostream>
#include "../include/utils.h"
#include "../include/data.h"

int main() {
    std::cout << "Demo of program lifecycle, memory layout, and exponentiation.\n";

    // Инициализация глобальных и статических переменных
    std::cout << "Initial global variable: " << global_var << "\n";
    initialize_static_variable();

    // Пример работы с r-value и l-value ссылками
    int base = 2;
    int exp = 10;

    // Демонстрация r-value и l-value
    std::cout << "Result of power(" << base << ", " << exp << ") = " << ::power(base, exp) << "\n";

    // Вызов функции с глобальными переменными
    manipulate_globals();

    return 0;
}