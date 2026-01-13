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
    void setPin(const short &pin);
    void invalidPINMessage() const;

private:
    short pin;
    short option;
    Screen current = Screen::LOGIN;
};

#endif