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
        cout << "Okay";
    else
        cout << "Not Okay";
}
