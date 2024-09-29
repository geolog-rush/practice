#include "1_circle_buf.h"

#include <gtest/gtest.h>

#include <vector>

namespace {

bool compare(auto c1, auto c2) {
    if (c1.size() != c2.size()) return false;

    while (!c1.empty())
        if (c1.pop() != c2.pop()) return false;

    return true;
}

bool compare(auto c1, std::vector<int> c2) {
    if (c1.size() != c2.size()) return false;

    std::size_t i{};
    while (!c1.empty())
        if (c1.pop() != c2[i++]) return false;

    return true;
}

}  // namespace

TEST(CircleBufTest, itWorks) {
    CircleBuf<int> buffer;

    buffer.push(1);
    buffer.push(3);
    buffer.push(5);
    EXPECT_TRUE(compare(buffer, std::vector{5, 3, 1}));

    EXPECT_EQ(buffer.pop(), 5);
    EXPECT_EQ(buffer.pop(), 3);
    EXPECT_TRUE(compare(buffer, std::vector{1}));

    buffer.push(4);
    EXPECT_TRUE(compare(buffer, std::vector{4, 1}));
}

TEST(CircleBufTest, overflow) {
    constexpr std::size_t size{3};
    CircleBuf<int, size> buffer;

    buffer.push(1);
    buffer.push(3);
    buffer.push(5);
    buffer.push(7);
    buffer.push(9);
    EXPECT_TRUE(compare(buffer, std::vector{9, 7, 5}));
}

TEST(CircleBufTest, emptyWorks) {
    CircleBuf<int> buffer;
    EXPECT_TRUE(compare(buffer, std::vector<int>{}));

    buffer.push(3);
    EXPECT_TRUE(compare(buffer, std::vector<int>{3}));

    EXPECT_EQ(buffer.pop(), 3);
    EXPECT_TRUE(compare(buffer, std::vector<int>{}));

    EXPECT_EQ(buffer.pop(), 0);
    EXPECT_TRUE(compare(buffer, std::vector<int>{}));

    EXPECT_EQ(buffer.pop(), 0);
    EXPECT_TRUE(compare(buffer, std::vector<int>{}));
}
