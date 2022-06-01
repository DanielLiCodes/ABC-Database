#ifndef __SORT_TEST_HPP__
#define __SORT_TEST_HPP__

#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <algorithm>  

using namespace std;

DatabaseManager* manager2 = new DatabaseManager();


//QuickSort

TEST(ARRAYDBTest, QuickSortTesting) {
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 10; i++) {
      manager2->getDatabase("test")->add("string test_s" + to_string(i));
   }
   manager2->getDatabase("test")->sort("quick");
   EXPECT_EQ("", manager2->getDatabase("test")->at(0)->print());
}


TEST(ARRAYDBTest, QuickSortTestingJSON) {
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 10; i++) {
      manager2->getDatabase("test3")->add("json test_j {\"key\":\"to_string(i)\"}");
   }
   manager2->getDatabase("test3")->sort("quick");
   EXPECT_EQ("{\"key\":\"0\"}", manager2->getDatabase("test3")->at(0)->print());
}

//Array selectionsort

TEST(ARRAYDBTest, SelectionSortTesting) {
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 10; i++) {
      manager2->getDatabase("test")->add("string test_s" + to_string(i));
   }
   manager2->getDatabase("test")->sort("selection");
   EXPECT_EQ(0, manager2->getDatabase("test")->at(0)->print());
}



TEST(ARRAYDBTest, SelectionSortTestingJSON) {
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 10; i++) {
      manager2->getDatabase("test3")->add("json test_j {\"key\":\"to_string(i)\"}");
   }
   manager2->getDatabase("test3")->sort("selection");
   EXPECT_EQ("{\"key\":\"0\"}", manager2->getDatabase("test3")->at(0)->print());
}


//BOGO

TEST(ARRAYDBTest, BogoSortTesting) {
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 3; i++) {
      manager2->getDatabase("test")->add("string test_s" + to_string(i));
   }
   manager2->getDatabase("test")->sort("bogo");
   EXPECT_EQ(0, manager2->getDatabase("test")->at(0)->print());
}

TEST(ARRAYDBTest, BogoSortTestingJSON) {
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 3; i++) {
      manager2->getDatabase("test3")->add("json test_j {\"key\":\"to_string(i)\"}");
   }
   manager2->getDatabase("test3")->sort("bogo");
   EXPECT_EQ("{\"key\":\"0\"}", manager2->getDatabase("test3")->at(0)->print());
}
//insetionSort

TEST(ARRAYDBTest, InsertionSortTesting) {
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 10; i++) {
      manager2->getDatabase("test")->add("string test_s" + to_string(i));
   }
   manager2->getDatabase("test")->sort("insertion");
   EXPECT_EQ(0, manager2->getDatabase("test")->at(0)->print());
}

TEST(ARRAYDBTest, InsertionSortTestingJSON) {
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 10; i++) {
      manager2->getDatabase("test3")->add("json test_j {\"key\":\"to_string(i)\"}");
   }
   manager2->getDatabase("test3")->sort("insertion");
   EXPECT_EQ("{\"key\":\"0\"}", manager2->getDatabase("test3")->at(0)->print());
}


#endif