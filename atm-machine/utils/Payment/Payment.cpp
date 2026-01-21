#include "Payment.hpp"
#include <iostream>

using namespace std;

Screen Payment::paymentMenu()
{
    system("cls");
    cout << "=============================================\n";
    cout << "|                   Payment                  |\n";
    cout << "=============================================\n\n";
    cout << "   Please select your options for payment \n";
    cout << " 1) Payment in USD" << "\t2) Payment in KHR \n"
         << " 3) Go back" << "\t\t4) Exit\n";
    cout << "\nEnter your choice: ";

    cin >> paymentOption;
    switch (paymentOption)
    {
    case 1:
        cout << "Payment in USD\n";
        waitForUser();
        break;
    case 2:
        cout << "Payment in KHR\n";
        waitForUser();
        break;
    case 3:
        cout << "Go back to Account Menu\n";
        waitForUser();
        return Screen::ACCOUNT_MENU;
        break;
    case 4:
        cout << "Thank you for using Le Fang ATM. Goodbye!\n";
        exit(0);
        break;
    default:
        cout << "Please Select options 1-4 only.\n";
        waitForUser();
        return Screen::Payment_MENU;
        break;
    }

    waitForUser();
    return Screen::Payment_MENU;
}