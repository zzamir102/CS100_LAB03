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

TEST(PowTest, PowEvaluateNegative) {
	Op* left = new Op(2.0);
	Op* right = new Op(-2.0);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->evaluate(), 0.25);
}

TEST(PowTest, PowStringifyNonZero) {
	Op* left = new Op(3.0);
	Op* right = new Op(6.0);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->stringify(), "(3.000000 ** 6.000000)");
}

TEST(PowTest, PowStringifyMultChild) {
	SevenEightMultMock* left = new SevenEightMultMock();
	Op* leftPow = new Op(2.0);
	Op* rightPow = new Op(3.0);
	Pow* rightChild = new Pow(leftPow, rightPow);
	Pow* test = new Pow(left, rightChild);
	EXPECT_EQ(test->stringify(), "(56.000000 ** 8.000000)");
}

TEST(PowTest, PowEvaluateMultChild) {
	SevenEightMultMock* left = new SevenEightMultMock();
	Op* leftPow = new Op(2.0);
	Op* rightPow = new Op(3.0);
	Pow* rightChild = new Pow(leftPow, rightPow);
	Pow* test = new Pow(left, rightChild);
	EXPECT_EQ(test->evaluate(), 96717311574016);
}




#endif
