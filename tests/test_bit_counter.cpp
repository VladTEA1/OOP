
#include <gtest/gtest.h>
#include "bit_counter.h"

// Тест из условия задачи
TEST(BitCounterTest, ExampleFromAssignment) {
    EXPECT_EQ(count_ones_in_range(2, 7), 11);
}

// Тест с одним числом
TEST(BitCounterTest, SingleNumber) {
    EXPECT_EQ(count_ones_in_range(5, 5), 2);  // 101 -> 2 единицы
    EXPECT_EQ(count_ones_in_range(1, 1), 1);  // 1 -> 1 единица
    EXPECT_EQ(count_ones_in_range(0, 0), 0);  // 0 -> 0 единиц
}

// Тест с малым диапазоном
TEST(BitCounterTest, SmallRange) {
    EXPECT_EQ(count_ones_in_range(0, 1), 1);  // 0,1 -> 0+1=1
    EXPECT_EQ(count_ones_in_range(1, 3), 4);  // 1,2,3 -> 1+1+2=4
}

// Тест с некорректным диапазоном
TEST(BitCounterTest, InvalidRange) {
    EXPECT_EQ(count_ones_in_range(10, 5), 0);
}

// Тест с граничными значениями
TEST(BitCounterTest, BoundaryValues) {
    EXPECT_EQ(count_ones_in_range(0, 10), 17);
}

// Тест с последовательными числами
TEST(BitCounterTest, ConsecutiveNumbers) {
    // 15(1111)=4, 16(10000)=1, 17(10001)=2 → 4+1+2=7
    EXPECT_EQ(count_ones_in_range(15, 17), 7);
}

// Тест с большими числами
TEST(BitCounterTest, LargeNumbers) {
    EXPECT_EQ(count_ones_in_range(100, 105), 12);
}