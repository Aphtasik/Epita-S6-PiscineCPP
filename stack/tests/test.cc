#include <gtest/gtest.h>

#include "../stack.hh"

TEST(basic, basic_creation)
{
    auto st = Stack<int>(20);    
}

TEST(basic, basic_push)
{
    auto st = Stack<int>(20);
    st.push(1);
    st += 2;
    st << 3;
}

TEST(basic, basic_pop)
{
    auto st = Stack<int>(20);
    st << 1 << 2 << 3;
    ASSERT_EQ(st.pop(), 3);
    ASSERT_EQ(--st, 2);
}

TEST(basic, basic_access)
{
    auto st = Stack<int>(5);
    st += 1;
    st += 2;
    st += 3;
    ASSERT_EQ(st[0], 3);
    ASSERT_EQ(st[2], 1);
}

TEST(basic, equal_stacks)
{
    auto x = Stack<int>(5);
    auto y = Stack<int>(5);
    x += 1;
    y += 1;
    ASSERT_TRUE(x == y);
}

TEST(basic, not_equal_stacks)
{
    auto x = Stack<int>(5);
    auto y = Stack<int>(5);
    x += 1;
    y += 2;
    ASSERT_FALSE(x == y);
}

TEST(basic, print_test)
{
    ::testing::internal::CaptureStdout();
    auto st = Stack<int>(5);
    st.push(1).push(2).push(3);
    st.print(std::cout);
    auto out = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out, "1 2 3");
}

TEST(basic, resize_test)
{
    auto st = Stack<int>(5);
    st += 1;
    st += 2;
    st += 3;
    ::testing::internal::CaptureStdout();
    st.resize(2);
    st.print(std::cout);
    auto out = ::testing::internal::GetCapturedStdout();
    ASSERT_EQ(out, "1 2");
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
