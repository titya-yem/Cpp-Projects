#ifndef UTILS_LOGIN_LOGIN_HPP
#define UTILS_LOGIN_LOGIN_HPP
#include <string>

using namespace std;

class Login
{
public:
    void loginAccount();
    void setPin(const short &pin);

private:
    string creditCard;
    string debitCard;
    string MasterCard;
    short pin;
    short cardChoice;
};

#endif