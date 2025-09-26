#include <iostream>
#include <string>
#include <windows.h>
#include "../include/bit_counter.h"

std::string get_binary(int number) {
    if (number == 0) return "0";
    std::string result;
    int temp = number;
    while (temp > 0) {
        result = (temp & 1 ? "1" : "0") + result;
        temp >>= 1;
    }
    return result;
}

int main() {
    
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    
    int start, end;
    
    std::cout << "Введите начало диапазона a (0 <= a): ";
    std::cin >> start;
    
    std::cout << "Введите конец диапазона b (b >= a): ";
    std::cin >> end;
    
    if (start < 0 || end < start) {
        std::cout << "Ошибка: некорректный диапазон" << std::endl;
        return 1;
    }
    
    int result = count_ones_in_range(start, end);
    
    std::cout << "Диапазон: [" << start << ", " << end << "]" << std::endl;
    std::cout << "Общее количество единиц: " << result << std::endl;
    
    int display_count = (end - start + 1) > 5 ? 5 : (end - start + 1);
    for (int i = start; i < start + display_count; i++) {
        std::string binary = get_binary(i);
        int ones = 0;
        int num = i;
        while (num > 0) {
            ones += num & 1;
            num >>= 1;
        }
        std::cout << i << " (двоичное: " << binary << ") содержит " << ones << " единиц" << std::endl;
    }
    
    if (end - start + 1 > 5) {
        std::cout << "..." << std::endl;
    }
    
    return 0;
}