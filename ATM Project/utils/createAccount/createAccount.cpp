#include <iostream>
#include <iomanip>
using namespace std;

void createAccount()
{
    cout << "╔══════════════════════════════════════╗\n";
    cout << "║    Please create an account with us  ║\n";
    cout << "╚══════════════════════════════════════╝\n\n";
    cout << "  1) Create Account\n";
    cout << "  2) Exit\n";
    cout << "\nSelect: ";

    short createAccOption;
    cin >> createAccOption;

    switch (createAccOption)
    // use creat account function
    {
    case 1:
        cout << "Account created successfully" << endl;
        break;
    case 2:
        // exit
        cout << "Thank you for visiting Le Fang ATM Service";
        break;
    };
};