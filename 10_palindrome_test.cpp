#include "10_palindrome.h"

#include <gtest/gtest.h>

namespace {

TEST(Palindrome, itWorks) {
    using practice::isPalindrome;

    EXPECT_TRUE(isPalindrome("n"));
    EXPECT_TRUE(isPalindrome("nan"));
    EXPECT_TRUE(isPalindrome("nagan"));
    EXPECT_TRUE(isPalindrome("naggan"));

    EXPECT_FALSE(isPalindrome("na"));
    EXPECT_FALSE(isPalindrome("nana"));
    EXPECT_FALSE(isPalindrome("anan"));
    EXPECT_FALSE(isPalindrome("Nn"));
}

}  // namespace
