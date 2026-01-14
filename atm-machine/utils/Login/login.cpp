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
        if (invalidPINMessage())
        {
            waitForUser();
            return Screen::LOGIN;
        }

        // main menu
        if (pin == 1234)
            return Screen::ACCOUNT_MENU;

        cout << "Incorrect PIN, Please try again. \n";
        waitForUser();
        return Screen::LOGIN;
    case 2:
        system("cls");
        cout << "===============================================\n";
        cout << "|            Welcome to Le Fang ATM           |\n";
        cout << "===============================================\n\n";
        cout << "\tYou have selected Dedit Card. \n";
        cout << "\n\tEnter your PIN (4 digits): ";

        cin >> pin;
        if (invalidPINMessage())
        {
            waitForUser();
            return Screen::LOGIN;
        }

        // main menu
        if (pin == 1234)
            return Screen::ACCOUNT_MENU;

        cout << "Incorrect PIN, Please try again. \n";
        waitForUser();
        return Screen::LOGIN;
    case 3:
        system("cls");
        cout << "=============================================\n";
        cout << "|           Welcome to Le Fang ATM          |\n";
        cout << "=============================================\n\n";
        cout << "\tYou have selected Master Card. \n";
        cout << "\n\tEnter your PIN (4 digits): ";

        cin >> pin;
        if (invalidPINMessage())
        {
            waitForUser();
            return Screen::LOGIN;
        }

        // main menu
        if (pin == 1234)
            return Screen::ACCOUNT_MENU;

        cout << "Incorrect PIN, Please try again. \n";
        waitForUser();
        return Screen::LOGIN;
    case 4:
        system("cls");
        cout << "Thank you for using Le Fang ATM. Goodbye!\n";
        exit(0);
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

bool Login::invalidPINMessage() const
{
    // if input is not number it will clear and throw error;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<short>::max(), '\n');
        return true;
    }
    return false;
}