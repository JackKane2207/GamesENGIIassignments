#include "discount.hpp"

bool Discount::eligible(bool isMember, bool spendOverThreshold, bool hasCoupon) const {
    return (isMember && spendOverThreshold) || hasCoupon;
}
