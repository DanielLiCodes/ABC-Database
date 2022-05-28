#ifndef __DATABASE_TEST_HPP__
#define __DATABASE_TEST_HPP__

#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
#include "../src/Nodes/JSONNode.cpp"

TEST(DBTest, getAllParameters){
   JSONDatabaseNode node = JSONDatabaseNode("Kurs");
   vector<string> params = node.getAllParameters("first second third fourth fifth");
   EXPECT_EQ("first", params.at(0));
   EXPECT_EQ("second", params.at(1));
   EXPECT_EQ("third", params.at(2));
   EXPECT_EQ("fourth", params.at(3));
   EXPECT_EQ("fifth", params.at(4));
}


TEST(DBTest, AddNode){
   JSONDatabaseNode node = JSONDatabaseNode("Kurs");
   node.add("/john/jogn");
   EXPECT_EQ("{\"john\":{\"jogn\":null}}", node.print());
}

TEST(DBTest, SetNode){
   JSONDatabaseNode node = JSONDatabaseNode("Kurs");
   node.set("/john/jogn 18");
   EXPECT_EQ("{\"john\":{\"jogn\":\"18\"}}", node.print());
}


TEST(DBTest, RenmovNode){
   JSONDatabaseNode node = JSONDatabaseNode("Kurs");
   node.set("/john/jogn 18");
   EXPECT_EQ("{\"john\":{\"jogn\":\"18\"}}", node.print());
}



#endif