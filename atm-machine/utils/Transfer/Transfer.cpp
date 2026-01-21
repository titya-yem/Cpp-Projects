#include "Transfer.hpp"

Screen Transfer::transferMenu()
{
    system("cls");
    cout << "=============================================\n";
    cout << "|                  Transfer                 |\n";
    cout << "=============================================\n";
    cout << "   Please select your options for transfer \n\n";
    cout << "\t1) Transfer" << "\t2) Go back \n"
         << "  \t\t3) Exit\n";
    cout << "\nEnter your choice: ";

    cin >> transferOption;
    switch (transferOption)
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
        return Screen::Transfer_Menu;
        break;
    }

    waitForUser();
    return Screen::Transfer_Menu;
}