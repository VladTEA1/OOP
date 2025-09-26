#include "../include/bit_counter.h"

unsigned long count_ones_in_range(unsigned long start, unsigned long end) {
    if (start > end) {
        return 0;
    }
    
    unsigned long total = 0;
    
    for (unsigned long num = start; num <= end; ++num) {
        unsigned long n = num;
        unsigned long ones = 0;
        
        while (n > 0) {
            ones += n & 1;
            n >>= 1;
        }
        
        total += ones;
    }
    
    return total;
}