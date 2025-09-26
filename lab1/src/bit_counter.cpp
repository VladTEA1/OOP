#include "C:/Users//Vlad/Desktop/Laby_oop/OOP-main/include/bit_counter.h"

namespace {

int count_ones(int value) {
    int count = 0;
    while (value > 0) {
        count += value & 1;
        value >>= 1;
    }
    return count;
}

}

int count_ones_in_range(int a, int b) {
    if (a < 0 || b < a) {
        return -1;
    }
    
    int total = 0;
    for (int i = a; i <= b; i++) {
        total += count_ones(i);
    }
    return total;
}