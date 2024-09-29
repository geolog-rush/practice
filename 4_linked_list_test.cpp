#include "4_linked_list.h"

#include <gtest/gtest.h>

#include <cstddef>
#include <vector>

namespace {

bool compare(const auto& container, const std::vector<int>& checkContainer) {
    auto* node = container.begin();
    std::size_t counter{};
    for (; node; node = node->next()) {
        if (node->getValue() != checkContainer[counter++]) return false;
    }

    return counter == checkContainer.size();
}

TEST(LinkedList, addRemove) {
    practice::LinkedList<int> container;
    container.add(5);
    container.add(3);
    container.add(4);

    EXPECT_TRUE(compare(container, std::vector{5, 3, 4}));

    container.add(1);
    EXPECT_TRUE(compare(container, std::vector{5, 3, 4, 1}));

    container.remove(std::size_t{0});
    EXPECT_TRUE(compare(container, std::vector{3, 4, 1}));

    container.remove(std::size_t{1});
    EXPECT_TRUE(compare(container, std::vector{3, 1}));

    container.remove(std::size_t{1});
    EXPECT_TRUE(compare(container, std::vector{3}));

    // noop
    container.remove(std::size_t{1});
    EXPECT_TRUE(compare(container, std::vector{3}));

    container.remove(std::size_t{0});
    EXPECT_TRUE(compare(container, std::vector<int>{}));

    // noop
    container.remove(std::size_t{3});
    EXPECT_TRUE(compare(container, std::vector<int>{}));

    container.add(5);
    container.add(3);
    container.remove(container.begin()->next());
    EXPECT_TRUE(compare(container, std::vector{5}));
}

TEST(LinkedList, reverse) {
    practice::LinkedList<int> container;
    container.add(5);
    container.add(4);
    container.add(3);

    container.reverse();
    EXPECT_TRUE(compare(container, std::vector{3, 4, 5}));

    container.add(6);
    EXPECT_TRUE(compare(container, std::vector{3, 4, 5, 6}));

    container.remove(std::size_t{0});
    EXPECT_TRUE(compare(container, std::vector{4, 5, 6}));

    container.remove(std::size_t{2});
    EXPECT_TRUE(compare(container, std::vector{4, 5}));

    container.reverse();
    container.add(3);
    EXPECT_TRUE(compare(container, std::vector{5, 4, 3}));

    container.remove(1);
    EXPECT_TRUE(compare(container, std::vector{5, 3}));
}

}  // namespace
