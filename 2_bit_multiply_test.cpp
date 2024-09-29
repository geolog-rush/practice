#include "2_bit_multiply.h"

#include <gtest/gtest.h>

namespace {

TEST(BitMultiply, itWorks) {
    using practice::bitMultiply;

    EXPECT_EQ((33*123), bitMultiply(33, 123));
    EXPECT_EQ(123, bitMultiply(1, 123));
    EXPECT_EQ(123, bitMultiply(123, 1));
    EXPECT_EQ(0, bitMultiply(123, 0));
    EXPECT_EQ(0, bitMultiply(0, 123));
}

}  // namespace
