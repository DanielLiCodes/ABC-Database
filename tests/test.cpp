#include "gtest/gtest.h"
#include "databaseTest.hpp" 
// #include "sortTests.hpp"
// #include "utilTest.hpp"



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
