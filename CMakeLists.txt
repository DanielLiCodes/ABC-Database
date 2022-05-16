CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(ABCDatabase)
SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(ABCdatabase
    src/main.cpp
)

ADD_EXECUTABLE(test
    tests/test.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)