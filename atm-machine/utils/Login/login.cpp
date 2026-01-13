#include "Login.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>
#include "../Screen/Screen.hpp"

using namespace std;

Screen Login::loginAccount()
{
    system("cls");
    // Allow user to select card type and enter PIN again and again
    cout << "===============================================\n";
    cout << "|            Welcome to Le Fang ATM           |\n";
    cout << "===============================================\n\n";
    cout << "\tPlease select your account type: \n";
    cout << "\t1) Credit Card\n";
    cout << "\t2) Debit Card\n";
    cout << "\t3) Master Card\n";
    cout << "\t4) Exit ATM\n";
    cout << "\n\tEnter your choice: ";

    // will change later when i finished
    // current = (option == 1)   ? Screen::LOGIN
    //           : (option == 2) ? Screen::LOGIN
    //           : (option == 3) ? Screen::LOGIN
    //           : (option == 4) ? Screen::EXIT
    //                           : Screen::LOGIN;
    cin >> option;
    switch (option)
    {
    case 1:
        system("cls");
        // if possible, fetch userName and print it to the terminal.
        cout << "===============================================\n";
        cout << "|            Welcome to Le Fang ATM           |\n";
        cout << "===============================================\n\n";
        cout << "\tYou have selected Credit Card. \n";
        cout << "\n\tEnter your PIN (4 digits): ";

        cin >> pin;
        // main menu
        if (pin == 1234)
        {
            // return Screen::ACCOUNT_MENU;
            cout << "You have selected 3";
        }

        invalidPINMessage();
        incorrectPIN();

        break;
    case 2:
        system("cls");
        cout << "===============================================\n";
        cout << "|            Welcome to Le Fang ATM           |\n";
        cout << "===============================================\n\n";
        cout << "\tYou have selected Dedit Card. \n";
        cout << "\n\tEnter your PIN (4 digits): ";

        cin >> pin;
        // main menu
        if (pin == 1234)
        {
            // return Screen::ACCOUNT_MENU;
            cout << "You have selected 3";
        }

        invalidPINMessage();
        incorrectPIN();

        break;
    case 3:
        system("cls");
        cout << "=============================================\n";
        cout << "|           Welcome to Le Fang ATM          |\n";
        cout << "=============================================\n\n";
        cout << "\tYou have selected Master Card. \n";
        cout << "\n\tEnter your PIN (4 digits): ";

        cin >> pin;
        // main menu
        if (pin == 1234)
        {
            // return Screen::ACCOUNT_MENU;
            cout << "You have selected 3";
        }

        invalidPINMessage();
        incorrectPIN();

        break;
    case 4:
        system("cls");
        cout << "Thank you for using Le Fang ATM. Goodbye!\n";
        return Screen::EXIT;
    default:
        cout << "Please Select options 1-4 only.\n";
        waitForUser();
        return Screen::LOGIN;
    }

    waitForUser();
    return Screen::LOGIN;
}

void Login::setPin(const short &pin)
{
    // will change logic when setting creating account
    this->pin = pin;
}

void Login::invalidPINMessage() const
{
    // if input is not number it will clear and throw error;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<short>::max(), '\n');
        throw invalid_argument("Invalid PIN format. Please enter numberic digits only.");
    }
}