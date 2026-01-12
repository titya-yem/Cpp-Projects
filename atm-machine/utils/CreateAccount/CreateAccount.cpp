#include <iostream>
#include <iomanip>
#include "CreateAccount.hpp"

using namespace std;

void CreateAccount::createAccountMenu()
{
    system("cls");
    while (true)
    {
        cout << "========================================\n";
        cout << "|          Creating an account         |\n";
        cout << "========================================\n\n";
        cout << " Please select your account type.\n";
        cout << " 1) Credit Card\n";
        cout << " 2) Debit Card\n";
        cout << " 3) Master Card\n";
        cout << " 4) Exit ATM\n";
        cout << " Please select: ";

        short createAccOption;
        cin >> createAccOption;
        switch (createAccOption)
        {
        case 1:
            // saveAccount();
            cout << "Your have selected Credit Card";
            break;
        case 2:
            cout << "Your have selected Debit Card";
            break;
        case 3:
            cout << "Your have selected Master Card";
            break;
        case 4:
            cout << "Thank you for visiting Le Fang ATM Service";
            exit(0);
        default:
            system("cls");
            cout << "Please Select options 1-4 only.\n";
        }
    }
}