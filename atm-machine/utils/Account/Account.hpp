#ifndef UTILS_ACCOUNT_ACCOUNT_HPP
#define UTILS_ACCOUNT_ACCOUNT_HPP
#include <iostream>
#include "../Screen/Screen.hpp"

using namespace std;

class Account
{
public:
    Screen mainMenu();

    Screen inputValidation(const string &message, const Screen &screen);
    bool pinValidation(const string &pinToCheck);

    void waitForUser();
    string trim(const string &s);

private:
    short menuOption;
};

#endif