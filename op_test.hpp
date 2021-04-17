#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpStringifyNum) {
    Op* test = new Op(8);
    EXPECT_EQ(test->stringify(), "8.000000");
}

#endif //__OP_TEST_HPP__
