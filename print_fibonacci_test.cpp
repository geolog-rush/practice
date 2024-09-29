#include "print_fibonacci.h"

#include <gtest/gtest.h>

#include <cstddef>

namespace {

using practice::getFibSeries;
using practice::getFibs;

TEST(Fibonacci, fibSeries) {
    EXPECT_EQ((std::vector<std::size_t>{1, 1, 2, 3, 5}), getFibSeries(5));
}

TEST(Fibonacci, fibNumber)
{
    std::size_t result{};
    auto getResult = [&result](std::size_t, std::size_t value) {
        result = value;
    };
    getFibs(22, getResult);
    EXPECT_EQ(17711, result);
}

}  // namespace
