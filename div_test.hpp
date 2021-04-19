#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"
#include "div.hpp"  
#include "add.hpp"

using namespace std;

TEST(DivTest, DivEvaluateNonzero) {
	Op* right = new Op(4.0);
	Op* left = new Op(8.0);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->evaluate(), 2.0);
}

TEST(DivTest, DivEvaluateNegative) {
	Op* right = new Op(10.0);
	Op* left = new Op(-19.0);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->evaluate(), -1.9);
}

TEST(DivTest, DivEvaluateTwoNegative) { 
	Op* right = new Op(-25.0);
	Op* left = new Op(-50.0);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->evaluate(), 2.0); 
}

TEST(DivTest, DivEvaluateZero) {
	Op* right = new Op(-56.0);
	Op* left = new Op(0.0);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->evaluate(), 0.0);
}

TEST(DivTest, DivStringifyNonZero) { 
	Op* right = new Op(56.0);
	Op* left = new Op(5.0);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->stringify(), "(5.000000 / 56.000000)"); 
} 

TEST(DivTest, DivEvaluateDivByZero) { 
	Op* right = new Op(0.0);
	Op* left = new Op(6.0);
	Div* test = new Div(left, right);
	EXPECT_NE(test->evaluate(), 6.0);
}

TEST(DivTest, DivEvaluateAddChild) {
	Op* right = new Op(5.0);
	Op* left = new Op(7.0);
	Add* leftChild = new Add(left, right);
	Op* rightChild = new Op(6.0);
	Div* test = new Div(leftChild, rightChild);
	EXPECT_EQ(test->evaluate(), 2.0); 
}


#endif


