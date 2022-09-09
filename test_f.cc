#include <gtest/gtest.h>

class TestF : public testing::Test
{
};

TEST_F(TestF, checkZero)
{
    int ret = 0;
    ASSERT_EQ(ret, 0);
}
