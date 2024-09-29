
#include "6_constant_O_array.h"

#include <gtest/gtest.h>

#include <array>
#include <cstdint>
#include <limits>
#include <utility>

namespace {

using practice::Table;

template <typename Table, std::size_t... Idx>
auto createDumper(const Table& table, std::index_sequence<Idx...>) {
    return [&]() {
        return std::array<int, std::index_sequence<Idx...>{}.size()>(
            {table.get(Idx)...});
    };
}

TEST(Constant_O_array, itWorks) {
    constexpr std::size_t maxSize{3};
    Table<maxSize> table;
    auto dumper = createDumper(table, std::make_index_sequence<maxSize>{});

    table.set(0, 10);
    table.set(1, 11);

    EXPECT_EQ(std::to_array({10, 11, 0}), dumper());

    table.set_all(20);
    EXPECT_EQ(std::to_array({20, 20, 20}), dumper());

    table.set(2, 12);
    EXPECT_EQ(std::to_array({20, 20, 12}), dumper());
}

TEST(Constant_O_array, counterOverflow) {
    constexpr std::size_t maxSize{3};
    using TableCounter = std::uint16_t;
    Table<maxSize, TableCounter> table;
    auto dumper = createDumper(table, std::make_index_sequence<maxSize>{});

    // Two sets for each iteration + set_all each 100 iteration.
    // So the counter should make at least two full circles.
    const std::size_t checkEvery{100};
    const auto max = std::numeric_limits<TableCounter>::max();
    for (std::size_t i = 1; i < max; ++i) {
        int item_0 = i % 2 ? 10 + 3 : 10 - 3;
        int item_2 = i % 3 ? 20 + 3 : 20 - 3;
        table.set(0, item_0);
        table.set(2, item_2);

        if (!(i % checkEvery)) {
            int item_1{i == checkEvery ? 0 : 33};
            EXPECT_EQ(std::to_array({item_0, item_1, item_2}), dumper());
            table.set_all(33);
            EXPECT_EQ(std::to_array({33, 33, 33}), dumper());
        }
    }
}

}  // namespace
