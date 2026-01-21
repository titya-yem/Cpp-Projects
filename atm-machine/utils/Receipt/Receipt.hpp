#ifndef UTILS_RECEIPT_RECEIPT_HPP
#define UTILS_RECEIPT_RECEIPT_HPP
#include <iostream>
#include "../../Screen/Screen.hpp"
#include "../Account/Account.hpp"

class Receipt : public Account
{
public:
    Screen receiptMenu();

private:
    short receiptOption;
};

#endif