#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"
#include "mult.hpp"

TEST(MultTest, MultEvaluateNonzero) { 
	Op* right = new Op(6.0);
	Op* left = new Op(8.0);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->evaluate(), 48);
}

TEST(MultTest, MultEvaluateNegative) {
	Op* right = new Op(5.0);
	Op* left = new Op(-10.0);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->evaluate(), -50.0);
}

TEST(MultTest, MultEvaluateTwoNegatives) {
	Op* right = new Op(-9.0);
	Op* left = new Op(-5.5);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->evaluate(), 49.5);
}

TEST(MultTest, MultEvaluateZero) { 
	Op* right = new Op(25);
	Op* left = new Op(0);
	Mult* test = new Mult(left, right); 
	EXPECT_EQ(test->evaluate(), 0);
}

TEST(MultTest, MultStringifyNonzero) { 
	Op* right = new Op(20.0);
	Op* left = new Op(25.0);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->stringify(), "(25.000000 * 20.000000)");
}

TEST(MultTest, MultStringifyNegative) {
	Op* right = new Op(-54.0);
	Op* left = new Op(26.0);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->stringify(), "(26.000000 * -54.000000)"); 
}


#endif
