#include <gtest/gtest.h>
#include "counting_change.cc"

TEST(basic, tmtc)
{
    ASSERT_EQ(count_change(5), 4);
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
