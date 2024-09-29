#include "5_number_missing.h"

#include <array>
#include <gtest/gtest.h>

namespace {

TEST(NumberMissing, oneMissing) {
    using practice::findOneMissingNumber;

    EXPECT_EQ(findOneMissingNumber(std::array{2, 3, 4}), 1);
    EXPECT_EQ(findOneMissingNumber(std::array{4, 1, 2}), 3);
    EXPECT_EQ(findOneMissingNumber(std::array{1}), 2);
    EXPECT_EQ(findOneMissingNumber(std::array{2}), 1);

    EXPECT_EQ(findOneMissingNumber(std::to_array<double>({2, 3, 4})), 1.);
    EXPECT_NE(practice::findMoreThanOneMissingNumber(std::array{3}), (std::vector{1, 2}));
}

}
