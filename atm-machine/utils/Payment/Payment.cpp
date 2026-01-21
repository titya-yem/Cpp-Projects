#include "Payment.hpp"

using namespace std;

Screen Payment::paymentMenu()
{
    system("cls");
    cout << "=============================================\n";
    cout << "|                   Payment                  |\n";
    cout << "=============================================\n";
    cout << "   Please select your options for payment \n\n";
    cout << "\t1) Payment" << "\t2) Go back \n"
         << "\t\t 3) Exit\n";
    cout << "\nEnter your choice: ";

    cin >> paymentOption;
    switch (paymentOption)
    {
    case 1:
        cout << "Payment\n";
        waitForUser();
        break;
    case 2:
        cout << "Go back to Account Menu\n";
        waitForUser();
        return Screen::ACCOUNT_Menu;
        break;
    case 3:
        system("cls");
        cout << "Thank you for using Le Fang ATM. Goodbye!\n";
        exit(0);
        break;
    default:
        cout << "Please Select options 1-3 only.\n";
        waitForUser();
        return Screen::Payment_Menu;
        break;
    }

    waitForUser();
    return Screen::Payment_Menu;
}