#ifndef UTILS_PAYMENT_PAYMENT_HPP
#define UTILS_PAYMENT_PAYMENT_HPP
#include <iostream>
#include "../../Screen/Screen.hpp"
#include "../Account/Account.hpp"
#include "../../config/Database.hpp"

class Payment : public Account
{
public:
    Screen paymentMenu();
    Screen showPaymentSuccessful();

private:
    short paymentMenuOption;
    short paymentSuccessfulOption;

    double paymentInUSD = 0.00;
    double paymentInKHR = 0.00;

    double currentBalanceInUSD = 0.00;
    double currentBalanceInKHR = 0.00;

    double newPaymentUSD;
    double newPaymentKHR;
};

#endif