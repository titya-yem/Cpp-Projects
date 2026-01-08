#include "Account.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>

using namespace std;

void Account::cardType()
{
    // Allow user to select card type and enter PIN again and again
    while (true)
    {
        cout << "=============================================\n";
        cout << "|           Welcome to Le Fang ATM          |\n";
        cout << "=============================================\n\n";
        cout << "Please select your account type: \n";
        cout << " 1) Credit Card\n";
        cout << " 2) Debit Card\n";
        cout << " 3) Master Card\n";
        cout << " 4) Exit ATM\n";
        cout << "\nEnter your choice: ";

        short cardChoice;
        cin >> cardChoice;
        system("cls");

        switch (cardChoice)
        {
        case 1:
            cout << "=============================================\n";
            cout << "|           Welcome to Le Fang ATM          |\n";
            cout << "=============================================\n\n";
            cout << "You have selected Credit Card. \n";
            cout << "\nEnter your PIN (4 digits): ";

            // Check Pin input validity
            cin >> pin;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
                throw invalid_argument("Invalid PIN format. Please enter numberic digits only.");
            }
            // if pin correct, proceed to transaction menu
            break;
        case 2:
            cout << "=============================================\n";
            cout << "|           Welcome to Le Fang ATM          |\n";
            cout << "=============================================\n\n";
            cout << "You have selected Dedit Card. \n";
            cout << "\nEnter your PIN (4 digits): ";

            // Check Pin input validity
            cin >> pin;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
                throw invalid_argument("Invalid PIN format. Please enter numberic digits only.");
            }
            // if pin correct, proceed to transaction menu
            break;
        case 3:
            cout << "=============================================\n";
            cout << "|           Welcome to Le Fang ATM          |\n";
            cout << "=============================================\n\n";
            cout << "You have selected Master Card. \n";
            cout << "\nEnter your PIN (4 digits): ";

            // Check Pin input validity
            cin >> pin;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
                throw invalid_argument("Invalid PIN format. Please enter numberic digits only.");
            }
            // if pin correct, proceed to transaction menu
            break;
        case 4:
            cout << "Thank you for using Le Fang ATM. Goodbye!\n";
            exit(0);
        }
    }
}

void Account::setPin(const int &pin)
{
    this->pin = pin;
}
