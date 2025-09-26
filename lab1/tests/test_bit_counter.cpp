#include <gtest/gtest.h>
#include "../include/bit_counter.h"

TEST(BitCounterTest, ExampleFromTask) {
    EXPECT_EQ(count_ones_in_range(2, 7), 11);
}

TEST(BitCounterTest, SingleNumber) {
    EXPECT_EQ(count_ones_in_range(5, 5), 2);
    EXPECT_EQ(count_ones_in_range(1, 1), 1);
    EXPECT_EQ(count_ones_in_range(8, 8), 1);
}

TEST(BitCounterTest, ZeroCase) {
    EXPECT_EQ(count_ones_in_range(0, 0), 0);
}

TEST(BitCounterTest, RangeWithZero) {
    EXPECT_EQ(count_ones_in_range(0, 1), 1);
    EXPECT_EQ(count_ones_in_range(0, 3), 4);
}

TEST(BitCounterTest, InvalidInput) {
    EXPECT_EQ(count_ones_in_range(5, 3), -1);
    EXPECT_EQ(count_ones_in_range(-1, 5), -1);
    EXPECT_EQ(count_ones_in_range(-5, -1), -1);
}

TEST(BitCounterTest, BoundaryValues) {
    EXPECT_EQ(count_ones_in_range(0, 10), 17);
    EXPECT_EQ(count_ones_in_range(0, 15), 32);
}

TEST(BitCounterTest, LargeRange) {
    EXPECT_EQ(count_ones_in_range(0, 7), 12);
}