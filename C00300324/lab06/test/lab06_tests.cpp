// Lab 06 - Logic coverage: predicate, clause, fixtures, gcov
// Name  : Jack Kane    
// Student ID: C00300324
//
// The unit under test is Discount::eligible in src/discount.cpp. 
// The predicate is:
//     (isMember && spendOverThreshold) || hasCoupon


#include <gtest/gtest.h>
#include "discount.hpp"

class DiscountFixture : public ::testing::Test {
protected:
    Discount d;   // fresh instance per test
};

// 
// Row 02: a coupon alone makes the customer eligible.
TEST_F(DiscountFixture, WorkedExample_CouponAlone) {
    EXPECT_TRUE(d.eligible(false, false, true));
}

// TODO(Task 2 - predicate coverage): add ONE more test so the suite has at
// least one row where the predicate is false and one where it is true.
TEST_F(DiscountFixture, PredicateCoverage_FalseRow) {
    EXPECT_FALSE(d.eligible(false, false, false));
}

// TODO(Task 3 - clause coverage): add tests so that isMember,
// spendOverThreshold and hasCoupon each take the value true in some test and
// false in some test. State in your report which rows you used.
TEST_F(DiscountFixture, ClauseCoverage_Rows) {
    EXPECT_TRUE(d.eligible(true, true, false));
}

// TODO(Task 3 - continued): add the rows that make (isMember &&
// spendOverThreshold) true with no coupon, and isMember true with
// spendOverThreshold false. These complete branch coverage of the && and ||.
TEST_F(DiscountFixture, MemberBelowThresholdWithoutCoupon) {
    EXPECT_FALSE(d.eligible(true, false, false));
}