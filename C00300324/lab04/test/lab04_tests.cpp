// Lab 04 - Prime Path Coverage
// Name  : Jack Kane
// StudentID: C00300324
//
// The unit under test is scanRegion( ) in src/region_scan.cpp. 
//
//
// Replace each FAIL( ) with real assertions. Add more TEST cases as you need
// them. A test "reaches" a node or edge by calling scanRegion( ) with a grid
// that forces execution down that part of the graph.

#include <gtest/gtest.h>
#include "region_scan.hpp"

// The following is an example test code provided as a starter code. 
// You can use the similar test format, and choosing the right assert from GoogleTest.
// Ideally, you should be able to write test cases for all FEASIBLE prime paths
// Just like we discussed in the lecture, Prime Path Coverage Subsumes Edge-Pair coverage, which in-turn subsumes Edge coverage.
// So in this lab, if all prime paths are covered (tests written for each), we automatically complete all the edges and the pairs.
TEST(ScanRegion, WorkedExample_PositiveMultipleOfThree) {
    Grid g = {{11, 11, 11}};//1 -> 2 -> 3 -> 4 -> 5 -> 4 -> 5 -> 4 -> 5 -> 4 -> 6 -> 2 -> 7 -> 8 -> 10 -> 11 -> 13 : P01, P02, P03, P19
    EXPECT_EQ(scanRegion(g), 33);
}

// TODO(Task 2 - node coverage): add tests so that, between them, every node
// of the graph is executed at least once. One more grid alongside the worked
// example is enough. Think about which grid drives the false arm of the
// sum > 10 decision and the default arm of the switch.
TEST(ScanRegion, NodeCoverage_SecondTest) {
    Grid g = {{7}};
    EXPECT_EQ(scanRegion(g), -7); //1 -> 2 -> 3 -> 4 -> 5 -> 4 -> 6 -> 2 -> 7 -> 9 -> 10 -> 12 -> 13  : P01, P03, P22
    g = {{12}};
    EXPECT_EQ(scanRegion(g), 12); //1 -> 2 -> 3 -> 4 -> 5 -> 4 -> 6 -> 2 -> 7 -> 8 -> 10 -> 11 -> 13 : 
}

// TODO(Task 3 - edge coverage): add the tests that cover the edges node
// coverage leaves out. The edge from the outer loop test straight to the code
// after the loops needs a grid the outer loop never enters.
TEST(ScanRegion, EdgeCoverage_EmptyRegion) {
    //FAIL() << "not implemented"; //edge coverage achieved from previous tests
}

// TODO(Task 4 - prime path tour): using the prime path list in the overview,
// add tests whose executions tour the feasible prime paths. Label each test
// with the prime path numbers it covers. Three of the listed prime paths are
// infeasible; you do not write tests for those, but you must explain in your
// report why they cannot be toured.
TEST(ScanRegion, PrimePath_Example) {
    Grid g = {};
    EXPECT_EQ(scanRegion(g), 0); //1 -> 2 -> 7 -> 9 -> 10 -> 11 -> 13 : P13

    g = {{}}; 
    EXPECT_EQ(scanRegion(g), 0); //1 -> 2 -> 3 -> 4 -> 6 -> 2 -> 7 -> 9 -> 10 -> 11 -> 13 : P04, P05, P17

    g = {{3}}; 
    EXPECT_EQ(scanRegion(g), 0); //1 -> 2 -> 3 -> 4 -> 5 -> 4 -> 6 -> 2 -> 7 -> 9 -> 10 -> 11 -> 13 : P01, P03, P21

    g = {{13}}; 
    EXPECT_EQ(scanRegion(g), 13); //1 -> 2 -> 3 -> 4 -> 5 -> 4 -> 6 -> 2 -> 7 -> 8 -> 10 -> 12 -> 13 : P01, P03, P20

    g = {{12}, {}}; 
    EXPECT_EQ(scanRegion(g), 12); //1 -> 2 -> 3 -> 4 -> 5 -> 4 -> 6 -> 2 -> 3 -> 4 -> 6 -> 2 -> 7 -> 8 -> 10 -> 11 -> 13
    //P01, P03, P07, P08, P10, P15

    g = {{13}, {}}; 
    EXPECT_EQ(scanRegion(g), 13); //1 -> 2 -> 3 -> 4 -> 5 -> 4 -> 6 -> 2 -> 3 -> 4 -> 6 -> 2 -> 7 -> 8 -> 10 -> 12 -> 13
    //P01, P03, P07, P08, P10, P16

    g = {{7}, {}}; 
    EXPECT_EQ(scanRegion(g), -7); //1 -> 2 -> 3 -> 4 -> 5 -> 4 -> 6 -> 2 -> 3 -> 4 -> 6 -> 2 -> 7 -> 9 -> 10 -> 12 -> 13
    //P01, P03, P07, P08, P10, P18

    g = {{}, {}, {1}};
    EXPECT_EQ(scanRegion(g), -1); //1 -> 2 -> 3 -> 4 -> 6 -> 2 -> 3 -> 4 -> 6 -> 2 -> 3 -> 4 -> 5 -> 4 -> 6 -> 2 -> 7 -> 9 -> 10 -> 12 -> 13
    //P04, P05, P06, P07, P09, P10, P22
}