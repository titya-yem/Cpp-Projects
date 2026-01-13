#include "Login.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>
#include "../Account/Account.hpp"

using namespace std;

void Login::loginAccount()
{
    system("cls");
    // Allow user to select card type and enter PIN again and again
    while (true)
    {
        cout << "===============================================\n";
        cout << "|            Welcome to Le Fang ATM           |\n";
        cout << "===============================================\n\n";
        cout << "\tPlease select your account type: \n";
        cout << "\t1) Credit Card\n";
        cout << "\t2) Debit Card\n";
        cout << "\t3) Master Card\n";
        cout << "\t4) Exit ATM\n";
        cout << "\n\tEnter your choice: ";

        cin >> cardChoice;
        system("cls");

        switch (cardChoice)
        {
        case 1:
            // if possible, fetch userName and print it to the terminal.
            cout << "===============================================\n";
            cout << "|            Welcome to Le Fang ATM           |\n";
            cout << "===============================================\n\n";
            cout << "\tYou have selected Credit Card. \n";
            cout << "\n\tEnter your PIN (4 digits): ";

            // Check Pin input validity
            cin >> pin;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
                throw invalid_argument("Invalid PIN format. Please enter numberic digits only.");
            }

            // if PIN is correct direct user to main menu
            if (pin == 1234)
            {
                Account account;
                account.mainMenu();
            }

            break;
        case 2:
            cout << "===============================================\n";
            cout << "|            Welcome to Le Fang ATM           |\n";
            cout << "===============================================\n\n";
            cout << "\tYou have selected Dedit Card. \n";
            cout << "\n\tEnter your PIN (4 digits): ";

            // Check Pin input validity
            cin >> pin;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
                throw invalid_argument("Invalid PIN format. Please enter numberic digits only.");
            }

            // main menu
            if (pin == 1234)
            {
                Account account;
                account.mainMenu();
            }

            break;
        case 3:
            cout << "=============================================\n";
            cout << "|           Welcome to Le Fang ATM          |\n";
            cout << "=============================================\n\n";
            cout << "\tYou have selected Master Card. \n";
            cout << "\n\tEnter your PIN (4 digits): ";

            // Check Pin input validity
            cin >> pin;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
                throw invalid_argument("Invalid PIN format. Please enter numberic digits only.");
            }

            // main menu
            if (pin == 1234)
            {
                Account account;
                account.mainMenu();
            }

            break;
        case 4:
            cout << "Thank you for using Le Fang ATM. Goodbye!\n";
            exit(0);
        }
    }
}

void Login::setPin(const short &pin)
{
    this->pin = pin;
}
