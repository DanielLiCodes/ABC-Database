#ifndef __UTIL_TEST_HPP__
#define __UTIL_TEST_HPP__

#include "gtest/gtest.h"
#include "../src/Nodes/JSONNode.cpp"


#include <string>
#include <iostream>
#include <vector>

using namespace std;

TEST(UtilTest, getAllParameters){
   JSONDatabaseNode node = JSONDatabaseNode("Kurs");
   vector<string> params = node.getAllParameters("first second third fourth fifth");
   EXPECT_EQ("first", params.at(0));
   EXPECT_EQ("second", params.at(1));
   EXPECT_EQ("third", params.at(2));
   EXPECT_EQ("fourth", params.at(3));
   EXPECT_EQ("fifth", params.at(4));
}


#endif