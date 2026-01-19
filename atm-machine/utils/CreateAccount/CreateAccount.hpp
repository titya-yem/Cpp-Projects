#ifndef UTILS_CREATEACCOUNT_CREATEACCOUNT_HPP
#define UTILS_CREATEACCOUNT_CREATEACCOUNT_HPP
#include "../Screen/Screen.hpp"
#include "../Account/Account.hpp"
#include "../../config/Database.hpp"
#include <string>

using namespace std;

class CreateAccount : public Account
{
public:
    Screen createAccountMenu();

    // Check is pin valid or not
    bool isValidPIN(const string &pin);

    // insert into DB
    bool insertAccount(const string &userName, const string &pin);

private:
    short createAccOption;
    string userName;
    string pin;
    Database db;
};

#endif