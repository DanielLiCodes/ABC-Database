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

TEST(HASHDBTest, createStringNode) {
   manager->createDatabase("test3", "hashTable");
   manager->getDatabase("test3")->add("string test lol pls work");
   EXPECT_EQ("lol pls work", manager->getDatabase("test3")->get("test")->print());
}
TEST(HASHDBTest, createJSONNode) {
   manager->createDatabase("test5", "hashTable");
   manager->getDatabase("test5")->add("json test {\"key\":\"value\"}");
   EXPECT_EQ("{\"key\":\"value\"}", manager->getDatabase("test5")->get("test")->print());
}


TEST(LinkedDBTest, createStringNode) {
   manager->createDatabase("test4", "hashTable");
   manager->getDatabase("test4")->add("lol hash test");
   EXPECT_EQ("lol hash test", manager->getDatabase("test4")->get("test")->print());
}
TEST(LinkedDBTest, createJSONNode) {
   manager->createDatabase("test", "hashTable");
   manager->getDatabase("test")->add("lol hash test");
   EXPECT_EQ("{\"key\":\"value\"}", manager->getDatabase("test")->get("test")->print());
}


TEST(ARRAYDBTest, returnSize) {
   manager->createDatabase("testSize", "array");
   manager->getDatabase("test3")->add("pos 1");
   manager->getDatabase("test3")->add("pos 2");
   manager->getDatabase("test3")->add("pos 3");
   EXPECT_EQ( 3, manager->getDatabase("test3")->size()->print());
}
TEST(LinkedDBTest, returnAt) {
   manager->createDatabase("testSize", "linkedList");
   manager->getDatabase("test2")->add("pos 0");
   manager->getDatabase("test2")->add("pos 1");
   manager->getDatabase("test2")->add("pos 2");
   EXPECT_EQ( 2, manager->getDatabase("test2")->at(1)->print());
}

#endif
