CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(ABCDatabase)
SET(CMAKE_CXX_STANDARD 17)
ADD_COMPILE_OPTIONS(-pthread -fPIC)


# -----------------
# Subdirectory
# -----------------
ADD_SUBDIRECTORY(googletest)
ADD_SUBDIRECTORY(pistache)
find_package(RapidJSON QUIET)
if (NOT RapidJSON_FOUND)
    message("RapidJSON not found. Consider installing it on your system. Downloading it from source...")
    include(FetchContent)
    FetchContent_Declare(
        RapidJSON
        GIT_REPOSITORY https://github.com/Tencent/rapidjson.git
        GIT_TAG v1.1.0
        GIT_SHALLOW true
    )
    set(RAPIDJSON_BUILD_DOC OFF CACHE BOOL "")
    set(RAPIDJSON_BUILD_EXAMPLES OFF CACHE BOOL "")
    set(RAPIDJSON_BUILD_TESTS OFF CACHE BOOL "")
    if(NOT RapidJSON_POPULATED)
        FetchContent_Populate(RapidJSON)
        add_subdirectory(${rapidjson_SOURCE_DIR} ${rapidjson_BINARY_DIR})
    endif()
    target_include_directories(pistache PRIVATE ${rapidjson_SOURCE_DIR}/include)
else()
    target_include_directories(pistache PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
endif()

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