#ifndef UTILS_CREATEACCOUNT_CREATEACCOUNT_HPP
#define UTILS_CREATEACCOUNT_CREATEACCOUNT_HPP
#include "../../Screen/Screen.hpp"
#include "../Account/Account.hpp"
#include "../../config/Database.hpp"
#include <string>

using namespace std;

class CreateAccount : public Account
{
public:
    CreateAccount();

    Screen createAccountMenu();

    // Check is pin valid or not
    bool isValidPIN(const string &pin);

    // insert into DB
    bool createAccount(const string &userName, const string &pin);

private:
    short createAccOption;
    Database db;

    int id;
    string userName;
    string pin;
    double balanceUSD;
    double balanceKHR;
};

#endif