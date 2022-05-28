CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(ABCDatabase)
SET(CMAKE_CXX_STANDARD 17)
ADD_COMPILE_OPTIONS(-pthread -fPIC)


# -----------------
# Subdirectory
# -----------------
ADD_SUBDIRECTORY(googletest)
ADD_SUBDIRECTORY(pistache)
include_directories(rapidjson)
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
set(THREADS_PREFER_PTHREAD_FLAG ON) 
find_package(Threads REQUIRED) 



# Pistache (HTTP)
TARGET_LINK_LIBRARIES(ABCdatabase pistache Threads::Threads)


# Google Test (TESTING)
TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)