#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__
#include <cstdlib>
#include "gtest/gtest.h"
#include "rand.hpp"

TEST(RandTest, RandEvaluateNonZero) {
	Rand* test = new Rand();
	double _value = rand() % 100;
	EXPECT_TRUE((test->evaluate()>= 0) && (test->evaluate() <= 99));
}

#endif
