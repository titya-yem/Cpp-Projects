#ifndef UTILS_RECEIPT_RECEIPT_HPP
#define UTILS_RECEIPT_RECEIPT_HPP
#include <iostream>
#include <vector>
#include "../../Screen/Screen.hpp"
#include "../Account/Account.hpp"

struct receiptType
{
    string type;
    double usd;
    double khr;
};

class Receipt : public Account
{
public:
    Screen receiptMenu();

    void action(const string &type, double usd, double khr);

private:
    short receiptOption;
    short receiptSuccessfulOption;

    // session only
    vector<receiptType> history;
};

#endif