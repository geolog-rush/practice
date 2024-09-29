#include "c_3_black_white_sort.h"

#include <gtest/gtest.h>

TEST(BlackWhileSort, itWorks)
{
    char source1[] = "010101";
    sortBlackWhite(source1);
    EXPECT_STREQ(source1, "000111");

    char source2[] = "111100";
    sortBlackWhite(source2);
    EXPECT_STREQ(source2, "001111");

    char source3[] = "000000";
    sortBlackWhite(source3);
    EXPECT_STREQ(source3, "000000");

    char source4[] = "111111";
    sortBlackWhite(source4);
    EXPECT_STREQ(source4, "111111");
}
