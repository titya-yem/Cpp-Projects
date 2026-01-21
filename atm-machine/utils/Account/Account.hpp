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
    Screen showAccountData(accountInformation &data);

    // store login user (userName & pin)
    void setCurrentUser(const string &userName, const string &pin);
    void waitForUser();

    const string &getUserName() const;
    const string &getPIN() const;

    // use protected because it is accessible in class such as
    // parent, and childs classes
protected:
    short accountOption;
    short accountInformationOption;
    string userName; // store Logged-in userName
    string pin;      // store Logged-in pin
};

#endif