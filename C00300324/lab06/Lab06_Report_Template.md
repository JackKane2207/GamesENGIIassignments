# Lab 06 — Report

**Full Name: Jack Kane** 
**Student ID: C00300324** 

## Build, test, coverage

```
cmake -S . -B build
cmake --build build --target lab06_tests
./build/lab06_tests --gtest_color=yes

cmake -S . -B build-cov -DCMAKE_CXX_FLAGS="--coverage" \
                        -DCMAKE_EXE_LINKER_FLAGS="--coverage"
cmake --build build-cov --target lab06_tests
./build-cov/lab06_tests
gcov -b build-cov/CMakeFiles/discount.dir/src/discount.cpp.gcno > coverage_summary.txt
```

## Coverage criteria

Predicate-coverage rows used: 1, 2
Clause-coverage rows used: 1, 2, 5, 7
Tests reported / passed: 4 / 4

## Coverage summary (paste the tail of coverage_summary.txt)

Lines executed:100.00% of 2
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
No calls
Creating 'discount.cpp.gcov'

Lines executed:100.00% of 2

## Report (250-500 words)

Explain the difference between Predicate Coverage and Clause Coverage. Give a pair of rows from the truth table that satisfies Predicate Coverage but not Clause Coverage, and say which clause is left unexercised. Then describe what gcov reported for `discount.cpp`: did your suite reach 100 % line coverage, 100 % branch coverage, or both, and what is the difference between those two numbers?

Predicate coverage requires both outputs of the function to be tested, for example in this lab these 2 tests:

TEST_F(DiscountFixture, WorkedExample_CouponAlone) {
    EXPECT_TRUE(d.eligible(false, false, true));
}


TEST_F(DiscountFixture, PredicateCoverage_FalseRow) {
    EXPECT_FALSE(d.eligible(false, false, false));
}

have different expected outputs, false and true which ensure that both outputs of the function have been tested as it can only be false or true which results in complete predicate coverage.

This does not cover clause coverage as the first 2 conditions (isMember and spendOverThreshold) are false in both tests.

Clause coverage requires all conditions to have been tested for true and false, that is covered with these 2 tests: 

TEST_F(DiscountFixture, WorkedExample_CouponAlone) {
    EXPECT_TRUE(d.eligible(false, false, true));
}

TEST_F(DiscountFixture, ClauseCoverage_Rows) {
    EXPECT_TRUE(d.eligible(true, true, false));
}

each condition is tested with both of its options, true and false to ensure that complete clause coverage is acquired.
Clause coverage does not ensure predicate coverage as in this example both tests return true.

I ran all four tests, and each one passed with the expected result.

The gcov report showed that my tests resulted in 100% line coverage and 100% branch coverage for discount.cpp.
Line coverage is the precentage of lines that were executed, for example mine is 100% of 2 executable lines, as the 2 lines:

bool Discount::eligible(bool isMember, bool spendOverThreshold, bool hasCoupon) const {
    return (isMember && spendOverThreshold) || hasCoupon;
}

were executed.

Branch coverage checks how many outcomes using each condition in the logic are tested, for example mine covers 100% of 6 which is the true and false for all 3 variables (isMember, spendOverThreshold, hasCoupon) resulting in 6 individual condition outcomes tested.

Full line coverage does not guarantee full branch coverage as line coverage is achieved as long as the executable lines are ran, full branch coverage is needed to actually test all individual conditions.


## Screenshots

* `screenshots/vscode.png`
* `screenshots/terminal.png`
