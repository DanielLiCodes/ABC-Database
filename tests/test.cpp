#include "gtest/gtest.h"
#include "databaseTest.hpp" 
#include "sortTests.hpp"
// #include "utilTest.hpp"



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  int hi = RUN_ALL_TESTS();
  delete manager2;
  return hi;
}
