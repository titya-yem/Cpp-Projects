#include "Payment.hpp"
#include <iostream>

using namespace std;

Screen Payment::paymentMenu()
{
    system("cls");
    // will user inheritance when checking the same as function of each of them
    cout << "==============================================\n";
    cout << "|                   Payment                  |\n";
    cout << "==============================================\n\n";
    cout << "    Please select your options for payment \n";
    cout << " 1) Payment in USD" << "\t2) Payment in KHR \n"
         << "\t3) Go back" << "\t6) Exit\n";
    cout << "\nEnter your choice: ";

    cin >> paymentOption;
    switch (paymentOption)
    {
    case 1:
        cout << "Payment in USD";
        waitForUser();
        break;
    case 2:
        cout << "Payment in KHR";
        waitForUser();
        break;
    case 3:
        cout << "Go back to Account Menu";
        waitForUser();
        return Screen::ACCOUNT_MENU;
    case 4:
        cout << "Thank you for using Le Fang ATM. Goodbye!\n";
        exit(0);
    default:
        cout << "Please Select options 1-4 only.\n";
        waitForUser();
        return Screen::Payment_MENU;
    }

    waitForUser();
    return Screen::Payment_MENU;
}