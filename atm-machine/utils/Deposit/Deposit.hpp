#ifndef UTILS_DEPOSIT_DEPOSIT_HPP
#define UTILS_DEPOSIT_DEPOSIT_HPP
#include <iostream>
#include "../../Screen/Screen.hpp"
#include "../Account/Account.hpp"

class Deposit : public Account
{
public:
    Screen depositMenu();

    Screen showDepositSuccessful(const double &usd, const double &khr);

private:
    short depositOption;
    short depositSuccessfulOption;

    double depositUSD = 0.00;
    double depositKHR = 0.00;

    double currentUSD = 0.00;
    double currentKHR = 0.00;
};

#endif