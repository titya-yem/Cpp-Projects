#include <iostream>
#include <iomanip>
#include "CreateAccount.hpp"

using namespace std;

void CreateAccount::createAccountMenu()
{
    cout << "========================================\n";
    cout << "|       Please create an account       |\n";
    cout << "========================================\n\n";
    cout << " 1) Please select account type: ";
    cout << " 2) Credit Card\n";
    cout << " 3) Debit Card\n";
    cout << " 4) Master Card\n";
    cout << " 5) Exit ATM\n";
    cout << "\nSelect: ";

    short createAccOption;
    cin >> createAccOption;
    system("cls");

    switch (createAccOption)
    {
    case 1:
        // saveAccount();
        break;
    case 2:
        cout << "Thank you for visiting Le Fang ATM Service";
        break;
    }
}