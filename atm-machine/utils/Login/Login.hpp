#ifndef UTILS_LOGIN_LOGIN_HPP
#define UTILS_LOGIN_LOGIN_HPP
#include <string>
#include "../Screen/Screen.hpp"
#include "../Account/Account.hpp"

using namespace std;

class Login : public Account
{
public:
    Screen loginAccount();

private:
    string userName;
    string pin;
    short option;
};

#endif