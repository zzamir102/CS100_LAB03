#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"
#include "mockTest.hpp"
#include "add.hpp"

TEST(AddTest, AddEvaluateNonZero) {
	Op* left = new Op(8.5);
	Op* right = new Op(10.0);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->evaluate(), 18.5);
}

TEST(AddTest, AddEvaluateNonDouble) {
	Op* left = new Op(9);
	Op* right = new Op(16);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->evaluate(), 25.0);
}

TEST(AddTest, AddEvaluateNegativeInputs) {
	Op* left = new Op(-9.0);
	Op* right = new Op(16.0);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->evaluate(), 7.000000);
}


TEST(AddTest, AddEvaluateAddZero) {
	Op* left = new Op(0.0);
	Op* right = new Op(10.0);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->evaluate(), 10.0);
}

TEST(AddTest, AddStringifyNonZero) {
	Op* left = new Op(9);
	Op* right = new Op(16);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->stringify(),"(9.000000 + 16.000000)");	
}

TEST(AddTest, AddStringifyAddZero) {
	Op* left = new Op(0.0);
	Op* right = new Op(10.0);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->stringify(), "(0.000000 + 10.000000)");
}

TEST(AddTest, AddStringifyNegativeInputs) {
	Op* left = new Op(9.0);
	Op* right = new Op(-16.0);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->stringify(), "(9.000000 + -16.000000)");
}

TEST(AddTest, ADDEvaluateMultChild) {
	SevenEightMultMock* left = new SevenEightMultMock();
	Op* leftAdd = new Op(9.0);
	Op* rightAdd = new Op(16.0);
	Add* right = new Add(leftAdd, rightAdd);
	Add * test = new Add(left, right);
	EXPECT_EQ(test->evaluate(), 81);
}

TEST(AddTest, AddStringifyMultChild) {
	SevenEightMultMock* left = new SevenEightMultMock();
	Op* leftAdd = new Op(9.0);
	Op* rightAdd = new Op(16.0);
	Add* right = new Add(leftAdd, rightAdd);
	Add * test = new Add(left, right);
	EXPECT_EQ(test->stringify(), "(56.000000 + 25.000000)");
}



#endif
