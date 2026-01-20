#ifndef UTILS_ACCOUNT_ACCOUNT_HPP
#define UTILS_ACCOUNT_ACCOUNT_HPP
#include <string>
#include "../../Screen/Screen.hpp"

using namespace std;

struct accountInformation
{
    int id;
    string userName;
    string pin;
    double balanceUSD;
    double balanceKHR;
};

class Account
{
public:
    Screen accountMenu();
    Screen accountData(accountInformation &data);

    void waitForUser();

private:
    short menuOption;
    string userName;
    string pin;
};

#endif