#ifndef UTILS_DEPOSIT_DEPOSIT_HPP
#define UTILS_DEPOSIT_DEPOSIT_HPP
#include <iostream>
#include "../../Screen/Screen.hpp"
#include "../Account/Account.hpp"
#include "../Receipt/Receipt.hpp"

class Deposit : public Account
{
public:
    Deposit(Receipt *receipt);

    Screen depositMenu();
    Screen showDepositSuccessful();

private:
    short depositOption;
    short depositSuccessfulOption;

    double depositUSD = 0.00;
    double depositKHR = 0.00;

    double currentUSD = 0.00;
    double currentKHR = 0.00;

    double newDepositUSD;
    double newDepositKHR;

    Receipt *receipt;
};

#endif