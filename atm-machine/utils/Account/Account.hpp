#ifndef UTILS_ACCOUNT_ACCOUNT_HPP
#define UTILS_ACCOUNT_ACCOUNT_HPP
#include <iostream>

using namespace std;

class Account
{
public:
    void cardType();
    void setPin(const int &pin);

private:
    string creditCard;
    string debitCard;
    string MasterCard;
    int pin;
};

#endif