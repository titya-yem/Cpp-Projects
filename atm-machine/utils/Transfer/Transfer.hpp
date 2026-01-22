#ifndef UTILS_TRANSFER_TRANSFER_HPP
#define UTILS_TRANSFER_TRANSFER_HPP
#include <iostream>
#include "../../Screen/Screen.hpp"
#include "../Account/Account.hpp"
#include "../../config/Database.hpp"

class Transfer : public Account
{
public:
    Screen transferMenu();
    Screen showTransferSuccessful();

private:
    short transferMenuOption;
    short transferSuccessfulOption;

    double transferInUSD = 0.00;
    double transferInKHR = 0.00;

    double currentBlanceInUSD = 0.00;
    double currentBlanceInKHR = 0.00;

    double newTransferUSD;
    double newTransferKHR;
};

#endif