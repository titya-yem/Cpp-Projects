#include <iostream>
#include "login.hpp"
using namespace std;

void LoginUser()
{
    cout << "====================================\n";
    cout << "|              Welcome             |\n";
    cout << "====================================\n\n";
    cout << "Please enter your PIN (4 digits): ";

    string pin;
    cin >> pin;

    if (pin == "right")
    {
        cout << "Okay";
    }
    else
    {
        cout << "password is incorrect\n";
        cout << " 1) Press 1 to TRY AGAIN\n";
        cout << " 2) Press 2 to EXIT\n";
    }
}
