CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(ABCDatabase)
SET(CMAKE_CXX_STANDARD 11)


# -----------------
# Subdirectory
# -----------------
ADD_SUBDIRECTORY(googletest)
ADD_SUBDIRECTORY(pistache)

# -----------------
# Executables
# -----------------
ADD_EXECUTABLE(ABCdatabase
    src/main.cpp
)
ADD_EXECUTABLE(test
    tests/test.cpp
)

# -----------------
# Linking Libraries
# -----------------

# Pistache (HTTP)
TARGET_LINK_LIBRARIES(ABCdatabase pistache)


# Google Test (TESTING)
TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)