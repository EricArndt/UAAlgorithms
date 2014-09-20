
#include "increment.h"
#include <gtest/gtest.h>

TEST(Increment, Zero) {
  EXPECT_EQ(1, increment(0));
}

TEST(Increment, One) {
  EXPECT_EQ(2, increment(1));
}

TEST(Increment, Large) {
  EXPECT_EQ(12345679, increment(12345678));
}

TEST(Increment, Negative) {
  EXPECT_EQ(-41, increment(-42));
}