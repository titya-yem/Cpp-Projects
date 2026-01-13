#ifndef UTILS_ACCOUNT_ACCOUNT_HPP
#define UTILS_ACCOUNT_ACCOUNT_HPP
#include <iostream>

using namespace std;

class Account
{
public:
    void mainMenu();
    void waitForUser();

private:
    short menuOption;
};

#endif