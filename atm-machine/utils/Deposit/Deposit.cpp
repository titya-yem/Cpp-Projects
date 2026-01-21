#include "Deposit.hpp"

using namespace std;

Screen Deposit::depositMenu()
{
    system("cls");
    cout << "==============================================\n";
    cout << "|                   Deposit                  |\n";
    cout << "==============================================\n\n";
    cout << "   Please select your options for deposit \n";
    cout << " 1) Deposit in USD" << "\t2) Deposit in KHR \n"
         << " 3) Go back" << "\t\t4) Exit\n";
    cout << "\nEnter your choice: ";

    cin >> depositOption;
    switch (depositOption)
    {
    case 1:
        cout << "Deposit in USD\n";
        waitForUser();
        break;
    case 2:
        cout << "Deposit in KHR\n";
        waitForUser();
        break;
    case 3:
        cout << "Go back to Account Menu\n";
        waitForUser();
        return Screen::ACCOUNT_Menu;
        break;
    case 4:
        cout << "Thank you for using Le Fang ATM. Goodbye!\n";
        exit(0);
        break;
    default:
        cout << "Please Select options 1-4 only.\n";
        waitForUser();
        return Screen::Deposit_Menu;
        break;
    }

    waitForUser();
    return Screen::Deposit_Menu;
}