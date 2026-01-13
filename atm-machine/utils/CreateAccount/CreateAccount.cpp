#include <iostream>
#include <iomanip>
#include "CreateAccount.hpp"

using namespace std;

void CreateAccount::createAccountMenu()
{
    system("cls");
    while (true)
    {
        cout << "==============================================\n";
        cout << "|             Creating an account            |\n";
        cout << "==============================================\n\n";
        cout << "\tPlease select your account type.\n";
        cout << "\t1) Credit Card\n";
        cout << "\t2) Debit Card\n";
        cout << "\t3) Master Card\n";
        cout << "\t4) Exit ATM\n";
        cout << "\n\tPlease select: ";

        short createAccOption;
        cin >> createAccOption;
        switch (createAccOption)
        {
        case 1:
            // saveAccount();
            system("cls");
            cout << "Your have selected Credit Card";
            break;
        case 2:
            system("cls");
            cout << "Your have selected Debit Card";
            break;
        case 3:
            system("cls");
            cout << "Your have selected Master Card";
            break;
        case 4:
            system("cls");
            cout << "Thank you for visiting Le Fang ATM Service";
            exit(0);
        default:
            system("cls");
            cout << "Please Select options 1-4 only.\n";
        }
    }
}