#include "3_seeding_random.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <iterator>
#include <unordered_set>

namespace {

TEST(SeedingRandom, itWorks) {
    using practice::generateInRange;

    auto result = generateInRange(20);
    using ItemType = decltype(result)::value_type;
    std::unordered_set<ItemType> checkSet;

    std::copy(result.begin(), result.end(),
              std::inserter(checkSet, checkSet.begin()));

    EXPECT_EQ(checkSet.size(), result.size());

    checkSet.clear();
    result = generateInRange(120000);
    std::copy(result.begin(), result.end(),
              std::inserter(checkSet, checkSet.begin()));
    EXPECT_EQ(checkSet.size(), result.size());

    checkSet.clear();
    result = generateInRange(1);
    std::copy(result.begin(), result.end(),
              std::inserter(checkSet, checkSet.begin()));
    EXPECT_EQ(checkSet.size(), result.size());

    checkSet.clear();
    result = generateInRange(0);
    std::copy(result.begin(), result.end(),
              std::inserter(checkSet, checkSet.begin()));
    EXPECT_EQ(checkSet.size(), result.size());
}

}  // namespace
