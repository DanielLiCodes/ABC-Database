#ifndef __DATABASE_TEST_HPP__
#define __DATABASE_TEST_HPP__

#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
#include "../src/DatabaseManager.cpp"

DatabaseManager* manager = new DatabaseManager();


// ------> ARRAY TESTS <----------

// Create & add items to array
TEST(ARRAYDBTest, createJSONNode) {
   manager->createDatabase("test", "array");
   manager->getDatabase("test")->add("json test_j {\"key\":\"value\"}");
   EXPECT_EQ("{\"key\":\"value\"}", manager->getDatabase("test")->get("test_j")->print());
}

TEST(ARRAYDBTest, createStringNode) {
   manager->createDatabase("test2", "array");
   manager->getDatabase("test2")->add("string test_s wassup");
   EXPECT_EQ("wassup", manager->getDatabase("test2")->get("test_s")->print());
}

// Set items in array
TEST(ARRAYDBTest, setJSONNode) {
   manager->getDatabase("test")->set("test_j {\"key\":\"newValue\"}");
   EXPECT_EQ("{\"key\":\"newValue\"}", manager->getDatabase("test")->get("test_j")->print());
}

TEST(ARRAYDBTest, setStringNode) {
   manager->getDatabase("test2")->set("test_s newValue");
   EXPECT_EQ("newValue", manager->getDatabase("test2")->get("test_s")->print());
}

// Remove items from array
TEST(ARRAYDBTest, removeJSONNode) {
   manager->createDatabase("test3", "array");
   manager->getDatabase("test3")->add("json test_j {\"key\":\"value\"}");
   manager->getDatabase("test3")->remove("test_j");
   EXPECT_EQ(0, manager->getDatabase("test3")->getSize());
}

TEST(ARRAYDBTest, removeStringNode) {
   manager->createDatabase("test4", "array");
   manager->getDatabase("test4")->add("string test_s wassup");
   manager->getDatabase("test4")->remove("test_s");
   EXPECT_EQ(0, manager->getDatabase("test4")->getSize());
}


TEST(ARRAYDBTest, removeDatabase) {
   manager->removeDatabase("test");
   manager->removeDatabase("test2");
   manager->removeDatabase("test3");
   manager->removeDatabase("test4");
   EXPECT_EQ(0, manager->getDatabases().size());
}





// ------> LINKED LIST TESTS <----------

// Create & add it4ems to linked list

TEST(LINKEDLISTDBTest, createJSONNode) {
   manager->createDatabase("test", "linkedlist");
   manager->getDatabase("test")->add("json test_j {\"key\":\"value\"}");
   EXPECT_EQ("{\"key\":\"value\"}", manager->getDatabase("test")->get("test_j")->print());
}

TEST(LINKEDLISTDBTest, createStringNode) {
   manager->createDatabase("test2", "linkedlist");
   manager->getDatabase("test2")->add("string test_s wassup");
   EXPECT_EQ("wassup", manager->getDatabase("test2")->get("test_s")->print());
}

// Set items in linkedlist
TEST(LINKEDLISTDBTest, setJSONNode) {
   manager->getDatabase("test")->set("test_j {\"key\":\"newValue\"}");
   EXPECT_EQ("{\"key\":\"newValue\"}", manager->getDatabase("test")->get("test_j")->print());
}

TEST(LINKEDLISTDBTest, setStringNode) {
   manager->getDatabase("test2")->set("test_s newValue");
   EXPECT_EQ("newValue", manager->getDatabase("test2")->get("test_s")->print());
}

// Remove items from linkedlist
TEST(LINKEDLISTDBTest, removeJSONNode) {
   manager->createDatabase("test3", "linkedlist");
   manager->getDatabase("test3")->add("json test_j {\"key\":\"value\"}");
   manager->getDatabase("test3")->remove("test_j");
   EXPECT_EQ(0, manager->getDatabase("test3")->getSize());
}

TEST(LINKEDLISTDBTest, removeStringNode) {
   manager->createDatabase("test4", "linkedlist");
   manager->getDatabase("test4")->add("string test_s wassup");
   manager->getDatabase("test4")->remove("test_s");
   EXPECT_EQ(0, manager->getDatabase("test4")->getSize());
}


TEST(LINKEDLISTDBTest, removeDatabase) {
   manager->removeDatabase("test");
   manager->removeDatabase("test2");
   manager->removeDatabase("test3");
   manager->removeDatabase("test4");
   EXPECT_EQ(0, manager->getDatabases().size());
}


// ------> HASH TABLE TESTS <----------

// Create & add it4ems to linked list

TEST(HASHTABLEDBTest, createJSONNode) {
   manager->createDatabase("test", "hashtable");
   manager->getDatabase("test")->add("json test_j {\"key\":\"value\"}");
   EXPECT_EQ("{\"key\":\"value\"}", manager->getDatabase("test")->get("test_j")->print());
}

TEST(HASHTABLEDBTest, createStringNode) {
   manager->createDatabase("test2", "hashtable");
   manager->getDatabase("test2")->add("string test_s wassup");
   EXPECT_EQ("wassup", manager->getDatabase("test2")->get("test_s")->print());
}

// Set items in hashtable
TEST(HASHTABLEDBTest, setJSONNode) {
   manager->getDatabase("test")->set("test_j {\"key\":\"newValue\"}");
   EXPECT_EQ("{\"key\":\"newValue\"}", manager->getDatabase("test")->get("test_j")->print());
}

TEST(HASHTABLEDBTest, setStringNode) {
   manager->getDatabase("test2")->set("test_s newValue");
   EXPECT_EQ("newValue", manager->getDatabase("test2")->get("test_s")->print());
}

// Remove items from hashtable
TEST(HASHTABLEDBTest, removeJSONNode) {
   manager->createDatabase("test3", "hashtable");
   manager->getDatabase("test3")->add("json test_j {\"key\":\"value\"}");
   manager->getDatabase("test3")->remove("test_j");
   EXPECT_EQ(0, manager->getDatabase("test3")->getSize());
}

TEST(HASHTABLEDBTest, removeStringNode) {
   manager->createDatabase("test4", "hashtable");
   manager->getDatabase("test4")->add("string test_s wassup");
   manager->getDatabase("test4")->remove("test_s");
   EXPECT_EQ(0, manager->getDatabase("test4")->getSize());
}


TEST(HASHTABLEDBTest, removeDatabase) {
   manager->removeDatabase("test");
   manager->removeDatabase("test2");
   manager->removeDatabase("test3");
   manager->removeDatabase("test4");
   EXPECT_EQ(0, manager->getDatabases().size());
}


#endif
