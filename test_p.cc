#include <gtest/gtest.h>

class TestPFixture : public ::testing::TestWithParam<int>
{
};

TEST_P(TestPFixture, checkNotZero)
{
    int input = GetParam();
    ASSERT_NE(input, 0);
}

INSTANTIATE_TEST_SUITE_P(
    TestP,
    TestPFixture,
    testing::Values(1, 2, 3)
);
