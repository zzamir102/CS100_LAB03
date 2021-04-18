#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"
#include "mockTest.hpp"
#include "pow.hpp"

TEST(PowTest, PowEvaluateNonZero) {
	Op* left = new Op(3.0);
	Op* right = new Op(6.0);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->evaluate(),729.000000);
} 

TEST(PowTest, PowEvaluateZero) {
	Op* left = new Op(10.0);
	Op* right = new Op(0.0);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->evaluate(), 1.0);
}


#endif
