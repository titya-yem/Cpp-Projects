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

    void setCurrentUser(const string &userName, const string &pin);
    void waitForUser();

private:
    short accountOption;
    short accountInformationOption;
    string userName;
    string pin;
};

#endif