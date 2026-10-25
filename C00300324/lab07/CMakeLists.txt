cmake_minimum_required(VERSION 3.14)
project(lab07_payment LANGUAGES CXX)

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

add_library(payment STATIC src/payment.cpp src/payment.hpp)
target_include_directories(payment PUBLIC src)

add_executable(lab07_tests test/lab07_tests.cpp)
target_link_libraries(lab07_tests PRIVATE payment GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(lab07_tests)
