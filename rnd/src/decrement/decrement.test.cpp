
#include "decrement.h"
#include <gtest/gtest.h>

TEST(Decrement, Zero) {
  EXPECT_EQ(-1, decrement(0));
}

TEST(Decrement, One) {
  EXPECT_EQ(0, decrement(1));
}

TEST(Decrement, Large) {
  EXPECT_EQ(12345677, decrement(12345678));
}

TEST(Decrement, Negative) {
  EXPECT_EQ(-43, decrement(-42));
}