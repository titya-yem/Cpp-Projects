#include "Account.hpp"
#include "../Screen/Screen.hpp"

Screen Account::mainMenu()
{
    system("cls");
    // will user inheritance when checking the same as function of each of them
    cout << "===============================================\n";
    cout << "|            Welcome to Le Fang ATM           |\n";
    cout << "===============================================\n\n";
    cout << "\tPlease select your options to check: \n";
    cout << " 1) Account" << "\t2) Balance" << "\t3) Transaction\n"
         << " 4) Payment" << "\t5) Receipt" << "\t6) Exit\n";
    cout << "\nEnter your choice: ";

    cin >> menuOption;
    system("cls");
    switch (menuOption)
    {
    case 1:
        cout << "===============================================\n";
        cout << "|            Welcome to Le Fang ATM           |\n";
        cout << "===============================================\n\n";
        cout << "\tYou have selected Account. \n";
        cout << "\n\tShow account history";

        break;
    case 2:
        cout << "===============================================\n";
        cout << "|            Welcome to Le Fang ATM           |\n";
        cout << "===============================================\n\n";
        cout << "\tYou have selected Balance. \n";
        cout << "\nBalance: ";

        break;
    case 3:
        cout << "=============================================\n";
        cout << "|           Welcome to Le Fang ATM          |\n";
        cout << "=============================================\n\n";
        cout << "\tYou have selected Transaction. \n";
        cout << "\nTransaction: ";

        break;
    case 4:
        cout << "=============================================\n";
        cout << "|           Welcome to Le Fang ATM          |\n";
        cout << "=============================================\n\n";
        cout << "\tYou have selected Payment. \n";
        cout << "\nPayment: ";

        break;
    case 5:
        cout << "=============================================\n";
        cout << "|           Welcome to Le Fang ATM          |\n";
        cout << "=============================================\n\n";
        cout << "\tYou have selected Receipt. \n";
        cout << "\nReceipt: ";

        break;
    case 6:
        cout << "Thank you for using Le Fang ATM. Goodbye!\n";
        exit(0);
    default:
        cout << "Please Select options 1-6 only.\n";
        waitForUser();
        return Screen::ACCOUNT_MENU;
    }

    waitForUser();
    return Screen::ACCOUNT_MENU;
}

void Account::waitForUser()
{
    // for waiting user such as invalid or retry
    cout << "Press Enter To Continue....";
    cin.get();
}
