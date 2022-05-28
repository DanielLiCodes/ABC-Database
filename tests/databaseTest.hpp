#ifndef __DATABASE_TEST_HPP__
#define __DATABASE_TEST_HPP__

#include "gtest/gtest.h"
#include <string>

#include "../headers/Nodes/DatabaseNode.h"
#include "../headers/Nodes/JSONNode.h"


TEST(DBTest, getAllParameters){
   DatabaseNode* db = new JSONDatabaseNode();
   vector<string> params1 = db->getAllParameters("first second third fourth fifth");
   EXPECT_EQ("first", params1.at(0));
   EXPECT_EQ(8, 8);
   EXPECT_EQ(8, 8);
   EXPECT_EQ(8, 8);

   // FINISH THIS MARCUS
}



#endif