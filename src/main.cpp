#include <iostream>
#include "bit_counter.h"

int main() {
    unsigned long a, b;
    
    std::cout << "Введите два числа a и b (a <= b): ";
    std::cin >> a >> b;
    
    if (a > b) {
        std::cerr << "Ошибка: a должно быть меньше или равно b" << std::endl;
        return 1;
    }
    
    unsigned long result = count_ones_in_range(a, b);
    std::cout << "Количество единиц в двоичных представлениях чисел от " 
              << a << " до " << b << " равно: " << result << std::endl;
    
    return 0;
}