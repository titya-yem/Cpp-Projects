#include "Transfer.hpp"

Screen Transaction::transferMenu()
{
    system("cls");
    cout << "=============================================\n";
    cout << "|                  Transfer                 |\n";
    cout << "=============================================\n\n";
    cout << "   Please select your options for Transfer \n";
    cout << " 1) Payment in USD" << "\t2) Payment in KHR \n"
         << " 3) Go back" << "\t\t4) Exit\n";
    cout << "\nEnter your choice: ";

    cin >> transferOption;
    switch (transferOption)
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
        return Screen::ACCOUNT_Menu;
        break;
    case 4:
        cout << "Thank you for using Le Fang ATM. Goodbye!\n";
        exit(0);
        break;
    default:
        cout << "Please Select options 1-4 only.\n";
        waitForUser();
        return Screen::Transfer_Menu;
        break;
    }

    waitForUser();
    return Screen::Transfer_Menu;
}