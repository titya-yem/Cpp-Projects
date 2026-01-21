#ifndef UTILS_TRANSFER_TRANSFER_HPP
#define UTILS_TRANSFER_TRANSFER_HPP
#include <iostream>
#include "../../Screen/Screen.hpp"
#include "../Account/Account.hpp"

class Transaction : public Account
{
public:
    Screen transferMenu();

private:
    short transferOption;
};

#endif