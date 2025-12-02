#include <iostream>
#include "createAccount.hpp"
using namespace std;

void createAccount()
{
    cout << "========================================\n";
    cout << "|    Please create an account with us  |\n";
    cout << "========================================\n\n";
    cout << "  1) Create Account\n";
    cout << "  2) Exit\n";
    cout << "\nSelect: ";

    short createAccOption;
    cin >> createAccOption;
    system("cls");

    switch (createAccOption)
    {
    case 1:
        cout << "Account created successfully" << endl;
        break;
    case 2:
        cout << "Thank you for visiting Le Fang ATM Service";
        break;
    }
}
