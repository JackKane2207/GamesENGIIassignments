// Lab 07 - MC/DC on a payment approval gate
// Name  : Jack Kane
// StudentID: C00300324
//
// Predicate: P = (A OR B) AND C AND G AND D
//
// Determination conditions (the minor values that make each major clause DETERMINE P):
//   A determines P when B=F, C=T, G=T, D=T
//   B determines P when A=F, C=T, G=T, D=T
//   C determines P when (A||B)=T, G=T, D=T   -> pick A=T, B=F
//   G determines P when (A||B)=T, C=T, D=T   -> pick A=T, B=F   (TODO)
//   D determines P when (A||B)=T, C=T, G=T   -> pick A=T, B=F   (TODO)

#include <gtest/gtest.h>
#include <string>
#include "payment.hpp"

struct Row {
    PaymentCtx ctx;
    bool expected;
    std::string label;
};

class CACC : public ::testing::TestWithParam<Row> {};
TEST_P(CACC, MatchesExpected) {
    Row r = GetParam();
    EXPECT_EQ(approvePayment(r.ctx), r.expected) << r.label;
}

// -------- Worked pairs for majors A, B, C --------
INSTANTIATE_TEST_SUITE_P(MajorsABC, CACC, ::testing::Values(
    Row{ {true,  false, true, true, true}, true,  "A=T det" },
    Row{ {false, false, true, true, true}, false, "A=F det" },

    Row{ {false, true,  true, true, true}, true,  "B=T det" },
    // (B=F row is the A=F row above)

    Row{ {true,  false, true,  true, true}, true,  "C=T det" },
    Row{ {true,  false, false, true, true}, false, "C=F det" }
));

//
INSTANTIATE_TEST_SUITE_P(MajorsGD, CACC, ::testing::Values(
    // TODO: G=T det with minors A=T,B=F,C=T,D=T
    Row{ {true, false, true, true,  true},  true,  "G=T det" },
    // TODO: G=F det with same minors
    Row{ {true, false, true, false, true},  false, "G=F det" },
    // TODO: D=T det with minors A=T,B=F,C=T,G=T
    Row{ {true, false, true, true,  true},  true,  "D=T det" },
    // TODO: D=F det with same minors
    Row{ {true, false, true, true,  false}, false, "D=F det" }
));
