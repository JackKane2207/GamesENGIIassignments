cmake_minimum_required(VERSION 3.14)
project(lab08_hvac LANGUAGES CXX)

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

add_library(hvac_controller STATIC src/hvac_controller.cpp src/hvac_controller.hpp)
target_include_directories(hvac_controller PUBLIC src)

# Small command-line driver for the automation script in Part 4.
add_executable(hvac_cli src/hvac_cli.cpp)
target_link_libraries(hvac_cli PRIVATE hvac_controller)

# test/ starts empty. Every .cpp file you add there is compiled into lab08_tests.
file(GLOB LAB08_TEST_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp)
if(LAB08_TEST_SOURCES)
    add_executable(lab08_tests ${LAB08_TEST_SOURCES})
    target_link_libraries(lab08_tests PRIVATE hvac_controller GTest::gtest_main)
    include(GoogleTest)
    gtest_discover_tests(lab08_tests)
else()
    message(STATUS "lab08: test/ is empty, so no test target yet. Add test/lab08_tests.cpp and re-run CMake.")
endif()
