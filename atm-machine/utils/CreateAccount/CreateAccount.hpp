#ifndef UTILS_CREATEACCOUNT_CREATEACCOUNT_HPP
#define UTILS_CREATEACCOUNT_CREATEACCOUNT_HPP
#include "../Screen/Screen.hpp"
#include "../Account/Account.hpp"

class CreateAccount : public Account
{
public:
    Screen createAccountMenu();

private:
    short createAccOption;
};

#endif