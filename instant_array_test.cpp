#include "instant_array.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>

namespace {

using practice::InstantArray;

TEST(InstantArrayTest, itWorks) {
    InstantArray source{std::array{1, 1, 1, 1}};
    EXPECT_EQ(source.getSource(), (std::array{1, 1, 1, 1}));

    source.setValue(3);
    EXPECT_EQ(source.getSource(), (std::array{3, 3, 3, 3}));
}

TEST(InstantArrayTest, bigNumberElementsWorks) {
    constexpr std::size_t maxSize = 1023;
    std::array<int, maxSize> checkArray;
    const int newValue{2};
    std::ranges::fill(checkArray, newValue);

    InstantArray source{std::array<int, maxSize>{}};
    source.setValue(newValue);
    EXPECT_EQ(source.getSource(), checkArray);
}

TEST(InstantArrayTest, overflow) {
    // Sure, complier can't allow it
    //constexpr std::size_t maxSize = 1024;
    //InstantArray source{std::array<int, maxSize>{}};
}

}  // namespace
