#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"
#include "mockTest.hpp"
#include "sub.hpp"

TEST(SubTest, SubEvaluateNonZero) {
	Op* left = new Op(8.5);
	Op* right = new Op(10.0);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->evaluate(), -1.5);
}

TEST(SubTest, SubEvaluateNegative) {
	Op* left = new Op(-18.5);
	Op* right = new Op(-10.2341);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->evaluate(), -8.2659);
}

TEST(SubTest, SubEvaluateZero) {
	Op* left = new Op(0);
	Op* right = new Op(12.44287);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->evaluate(), -12.44287);
}

TEST(SubTest, SubStringifyNonZero) {
	Op* left = new Op(8.5);
	Op* right = new Op(10.0);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->stringify(),"(8.500000 - 10.000000)");
}

TEST(SubTest, SubStringifyAddleftChild) {
	Op* left = new Op(8.5);
	Op* right = new Op(10.0);
	Add* leftChild = new Add(left, right);
	Op* rightChild = new Op(5.0);
	Sub* test = new Sub(leftChild, rightChild);
	EXPECT_EQ(test->stringify(), "(18.500000 - 5.000000)");
}

TEST(SubTest, SubEvaluateMultleftChild) {
	SevenEightMultMock* leftChild = new SevenEightMultMock();
	Op* rightChild = new Op(5.0);
	Sub* test = new Sub(leftChild, rightChild);
	EXPECT_EQ(test->stringify(), "(56.000000 - 5.000000)");

}
#endif
