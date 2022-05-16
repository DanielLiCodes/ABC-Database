#ifndef __DATABASE_TEST_HPP__
#define __DATABASE_TEST_HPP__

#include "gtest/gtest.h"
#include <string>

TEST(PowTest, EvalPow){
   EXPECT_EQ(8, 8);
}

TEST(PowTest, EvalPowString) {
    EXPECT_EQ(8, 8);
}

TEST(PowTest, EvalPowNeg){
   EXPECT_EQ(8, 8);
}

#endif