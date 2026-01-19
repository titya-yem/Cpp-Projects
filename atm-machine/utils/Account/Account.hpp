#ifndef UTILS_ACCOUNT_ACCOUNT_HPP
#define UTILS_ACCOUNT_ACCOUNT_HPP
#include <iostream>
#include "../Screen/Screen.hpp"

using namespace std;

class Account
{
public:
    Screen mainMenu();
    void waitForUser();

private:
    short menuOption;
};

#endif