Создание программы, которая демонстрирует использование глобальных, статических, локальных переменных, а также вызов функций с различными типами аргументов (l-value и r-value ссылки). Мы будем использовать алгоритм быстрого возведения в степень через деление на 2, и разложим его на несколько файлов. 

### Пример программы:

#### Структура файлов:
1. `main.cpp` — основной файл.
2. `utils.h` — заголовочный файл с объявлением функций.
3. `utils.cpp` — реализация функций.
4. `data.h` — заголовочный файл для глобальных переменных.
5. `data.cpp` — файл с определениями глобальных переменных и их инициализацией.

### Файлы программы:

#### `main.cpp`
```cpp
#include <iostream>
#include "utils.h"
#include "data.h"

int main() {
    std::cout << "Demo of program lifecycle, memory layout, and exponentiation.\n";

    // Инициализация глобальных и статических переменных
    std::cout << "Initial global variable: " << global_var << "\n";
    initialize_static_variable();

    // Пример работы с r-value и l-value ссылками
    int base = 2;
    int exp = 10;

    // Демонстрация r-value и l-value
    std::cout << "Result of power(" << base << ", " << exp << ") = " << power(base, exp) << "\n";

    // Вызов функции с глобальными переменными
    manipulate_globals();

    return 0;
}
```

#### `utils.h`
```cpp
#ifndef UTILS_H
#define UTILS_H

// Функция для возведения числа в степень (быстрое возведение в степень через деление на 2)
int power(int base, int exp);

// Функция для работы с глобальными и статическими переменными
void manipulate_globals();

// Функция для инициализации статической переменной
void initialize_static_variable();

#endif
```

#### `utils.cpp`
```cpp
#include "utils.h"
#include "data.h"
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
```

#### `data.h`
```cpp
#ifndef DATA_H
#define DATA_H

// Глобальная переменная
extern int global_var;

#endif
```

#### `data.cpp`
```cpp
#include "data.h"

// Определение глобальной переменной
int global_var = 42;
```

### Инструкция по сборке и запуску:
1. **Компиляция и линковка:**
   Можно использовать следующий `Makefile` для сборки:
   ```makefile
   CC = g++
   CFLAGS = -Wall -std=c++11

   all: program

   program: main.o utils.o data.o
    $(CC) $(CFLAGS) -o program main.o utils.o data.o

   main.o: main.cpp utils.h data.h
    $(CC) $(CFLAGS) -c main.cpp

   utils.o: utils.cpp utils.h data.h
    $(CC) $(CFLAGS) -c utils.cpp

   data.o: data.cpp data.h
    $(CC) $(CFLAGS) -c data.cpp

   clean:
    rm -f *.o program
   ```

2. **Запуск:**
   ```bash
   make
   ./program
   ```

### Описание программы:

- **Глобальные и статические переменные**: 
  - Глобальная переменная `global_var` инициализируется значением `42`. В функции `manipulate_globals` мы изменяем значение этой переменной.
  - Статическая переменная `static_var` инициализируется один раз в функции `initialize_static_variable`.

- **Алгоритм быстрого возведения в степень**: 
  - Алгоритм использует деление экспоненты на 2. Если степень нечетная, результат умножается на базу. В каждой итерации база возводится в квадрат.

- **Работа с l-value и r-value**: 
  - В программе вызывается функция `power` с обычными переменными, что демонстрирует стандартную работу с l-value.

- **Многомодульная структура**: 
  - Код разбит на несколько файлов, что соответствует требованию многомодульной программы.

### Анализ программы:
1. **Препроцессинг**: 
   - Используя `gcc -E main.cpp`, можно просмотреть результат препроцессинга с включением заголовочных файлов и заменой макросов.

2. **Компиляция в объектные файлы**:
   - Компилируем каждый файл в объектный файл и изучаем таблицы символов с помощью `nm` и `objdump`.

3. **Линковка**:
   - Объединение всех объектных файлов в исполняемый файл и анализ содержимого сегментов кода и данных.

4. **Анализ виртуальной памяти**:
   - С помощью утилит `gdb` и `/proc/<pid>/maps` можно исследовать распределение памяти и маппинг сегментов программы на физическую память.

Этот пример можно расширять в зависимости от лекционного материала, добавляя новые функции и типы данных.