cmake_minimum_required(VERSION 3.14)
project(lab06_discount LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(discount STATIC src/discount.cpp src/discount.hpp)
target_include_directories(discount PUBLIC src)

add_executable(lab06_tests test/lab06_tests.cpp)
target_link_libraries(lab06_tests PRIVATE discount GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(lab06_tests)
