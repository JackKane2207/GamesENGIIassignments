#include "payment.hpp"

bool approvePayment(const PaymentCtx& c) {
    return (c.panBasicValid || c.hasStoredToken)
        && c.amountWithinLimit
        && c.gatewayUp
        && c.notBlacklisted;
}
