#include "gtest/gtest.h"
#include "sortTests.hpp"
#include "databaseTest.hpp"
// #include "utilTest.hpp"




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
