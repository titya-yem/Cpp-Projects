#ifndef UTILS_DEPOSIT_DEPOSIT_HPP
#define UTILS_DEPOSIT_DEPOSIT_HPP
#include <iostream>
#include "../../Screen/Screen.hpp"
#include "../Account/Account.hpp"

class Deposit : public Account
{
public:
    Screen depositMenu();

private:
    short depositOption;
};

#endif