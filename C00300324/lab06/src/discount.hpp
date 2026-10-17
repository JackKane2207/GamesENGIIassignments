#pragma once

class Discount {
public:
    bool eligible(bool isMember, bool spendOverThreshold, bool hasCoupon) const;
};
