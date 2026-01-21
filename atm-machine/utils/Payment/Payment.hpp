#ifndef UTILS_PAYMENT_PAYMENT_HPP
#define UTILS_PAYMENT_PAYMENT_HPP
#include <iostream>
#include "../../Screen/Screen.hpp"
#include "../Account/Account.hpp"

class Payment : public Account
{
public:
    Screen paymentMenu();

private:
    short paymentOption;
};

#endif