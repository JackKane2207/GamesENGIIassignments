#pragma once

struct PaymentCtx {
    bool panBasicValid;       // A
    bool hasStoredToken;      // B
    bool amountWithinLimit;   // C
    bool gatewayUp;           // G
    bool notBlacklisted;      // D
};

bool approvePayment(const PaymentCtx& ctx);
