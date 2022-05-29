#ifndef __DATABASE_TEST_HPP__
#define __DATABASE_TEST_HPP__

#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
#include "../src/DatabaseManager.cpp"

DatabaseManager* manager = new DatabaseManager();

TEST(ARRAYDBTest, createJSONNode) {
   manager->createDatabase("test", "array");
   manager->getDatabase("test")->add("json test {\"key\":\"value\"}");
   EXPECT_EQ("{\"key\":\"value\"}", manager->getDatabase("test")->get("test")->print());
}

TEST(ARRAYDBTest, createStringNode) {
   manager->createDatabase("test2", "array");
   manager->getDatabase("test2")->add("string test wassup");
   EXPECT_EQ("wassup", manager->getDatabase("test2")->get("test")->print());
}


// NOW TEST HASHTABLE DATABASE
// NOW TEST LINKEDLIST DATABASE
// MAKE SURE TESTING IS DONE WITH DIFFERENT DATABASES IE. TEST3, TEST4, TEST5


#endif