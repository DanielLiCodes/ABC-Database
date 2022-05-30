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

TEST(ARRAYDBTest, setJSONNode) {
   manager->createDatabase("test3", "array");
   manager->getDatabase("test3")->set("test3 {\"key\":\"value\"}");
   EXPECT_EQ("{\"key\":\"value\"}", manager->getDatabase("test3")->get("test")->print());
}

TEST(ARRAYDBTest, setStringNode) {
   manager->createDatabase("test4", "array");
   manager->getDatabase("test4")->set("test4 hello");
   EXPECT_EQ("hello", manager->getDatabase("test4")->get("test")->print());
}

TEST(ARRAYDBTest, removeJSONNode) {
   manager->createDatabase("test5", "array");
   manager->getDatabase("test5")->add("test5", "test")
   manager->getDatabase("test5")->remove("test");
   EXPECT_EQ(0, manager->getDatabase("test5")->getSize());
}

TEST(ARRAYDBTest, removeStringNode) {
   manager->createDatabase("test6", "array");
   manager->getDatabase("test6")->add("test6", "test")
   manager->getDatabase("test6")->remove("test");
   EXPECT_EQ(0, manager->getDatabase("test6")->getSize());
}

// Hashtable tests
TEST(HASHDBTest, createStringNode) {
   manager->createDatabase("test7", "hashtable");
   manager->getDatabase("test7")->add("string test lol pls work");
   EXPECT_EQ("lol pls work", manager->getDatabase("test7")->get("test")->print());
}

TEST(HASHDBTest, createJSONNode) {
   manager->createDatabase("test8", "hashtable");
   manager->getDatabase("test8")->add("json test {\"key\":\"value\"}");
   EXPECT_EQ("{\"key\":\"value\"}", manager->getDatabase("test8")->get("test")->print());
}

TEST(HASHDBTest, setStringNode) {
   manager->createDatabase("test9", "array");
   manager->getDatabase("test9")->set("test9 hello");
   EXPECT_EQ("hello", manager->getDatabase("test9")->get("test")->print());
}

TEST(HASHDBTest, setJSONNode) {
   manager->createDatabase("test10", "array");
   manager->getDatabase("test10")->set("test10 {\"key\":\"value\"}");
   EXPECT_EQ("{\"key\":\"value\"}", manager->getDatabase("test10")->get("test")->print());
}

TEST(HASHDBTest, removeStringNode) {
   manager->createDatabase("test11", "array");
   manager->getDatabase("test11")->add("test11", "test")
   manager->getDatabase("test11")->remove("test");
   EXPECT_EQ(0, manager->getDatabase("test11")->getSize());
}

TEST(HASHDBTest, removeJSONNode) {
   manager->createDatabase("test12", "array");
   manager->getDatabase("test12")->add("test12", "test")
   manager->getDatabase("test12")->remove("test");
   EXPECT_EQ(0, manager->getDatabase("test12")->getSize());
}


// LinkedDBTest
TEST(LinkedDBTest, createStringNode) {
   manager->createDatabase("test13", "linkedlist");
   manager->getDatabase("test13")->add("lol hash test");
   EXPECT_EQ("lol hash test", manager->getDatabase("test13")->get("test")->print());
}

TEST(LinkedDBTest, createJSONNode) {
   manager->createDatabase("test14", "linkedlist");
   manager->getDatabase("test14")->add("json test {\"key\":\"value\"}");
   EXPECT_EQ("{\"key\":\"value\"}", manager->getDatabase("test14")->get("test")->print());
}

TEST(LinkedDBTest, setStringNode) {
   manager->createDatabase("test15", "array");
   manager->getDatabase("test15")->set("test15 hello");
   EXPECT_EQ("hello", manager->getDatabase("test15")->get("test")->print());
}

TEST(LinkedDBTest, setJSONNode) {
   manager->createDatabase("test16", "array");
   manager->getDatabase("test16")->set("test16 {\"key\":\"value\"}");
   EXPECT_EQ("{\"key\":\"value\"}", manager->getDatabase("test16")->get("test")->print());
}

TEST(LinkedDBTest, removeStringNode) {
   manager->createDatabase("test17", "array");
   manager->getDatabase("test17")->add("test17", "test")
   manager->getDatabase("test17")->remove("test");
   EXPECT_EQ(0, manager->getDatabase("test17")->getSize());
}

TEST(LinkedDBTest, removeJSONNode) {
   manager->createDatabase("test18", "array");
   manager->getDatabase("test18")->add("test18", "test")
   manager->getDatabase("test18")->remove("test");
   EXPECT_EQ(0, manager->getDatabase("test18")->getSize());
}
// TEST(ARRAYDBTest, returnSize) {
// //    manager->createDatabase("testSize", "array");
// //    manager->getDatabase("test3")->add("pos 1");
// //    manager->getDatabase("test3")->add("pos 2");
// //    manager->getDatabase("test3")->add("pos 3");
// //    EXPECT_EQ( 3, manager->getDatabase("test3")->size()->print());
// // }
//
// // TEST(LinkedDBTest, returnAt) {
// //    manager->createDatabase("testSize", "linkedList");
// //    manager->getDatabase("test2")->add("pos 0");
// //    manager->getDatabase("test2")->add("pos 1");
// //    manager->getDatabase("test2")->add("pos 2");
// //    EXPECT_EQ( 2, manager->getDatabase("test2")->at(1)->print());
// // }
//
// // TEST(HASHDBTest, createStringNode) {
// //    manager->createDatabase("test3", "hashTable");
// //    manager->getDatabase("test3")->add("lol hash test");
// //    EXPECT_EQ("wassup", manager->getDatabase("test3")->get("test")->print());
// // }

#endif
