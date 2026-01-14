#include "Account.hpp"
#include "limits"

void Account::mainMenu()
{
    system("cls");
    // Allow user to select card type and enter PIN again and again
    // if possible fetch userName from db and shows here.
    cout << "===============================================\n";
    cout << "|            Welcome to Le Fang ATM           |\n";
    cout << "===============================================\n\n";
    cout << "\tPlease select your options: \n";
    cout << "1) Account" << "\t2) Balance" << "\t3) Transaction\n"
         << "4) Payment" << "\t5) Receipt" << "\t6) Exit\n";
    cout << "\nEnter your choice: ";

    cin >> menuOption;
    system("cls");

    switch (menuOption)
    {
    case 1:
        system("cls");
        cout << "===============================================\n";
        cout << "|            Welcome to Le Fang ATM           |\n";
        cout << "===============================================\n\n";
        cout << "\tYou have selected Account. \n";
        cout << "\n\tShow account history";

        break;
    case 2:
        system("cls");
        cout << "===============================================\n";
        cout << "|            Welcome to Le Fang ATM           |\n";
        cout << "===============================================\n\n";
        cout << "\tYou have selected Balance. \n";
        cout << "\nBalance: ";

        break;
    case 3:
        system("cls");
        cout << "=============================================\n";
        cout << "|           Welcome to Le Fang ATM          |\n";
        cout << "=============================================\n\n";
        cout << "\tYou have selected Transaction. \n";
        cout << "\nTransaction: ";

        break;
    case 4:
        system("cls");
        cout << "=============================================\n";
        cout << "|           Welcome to Le Fang ATM          |\n";
        cout << "=============================================\n\n";
        cout << "\tYou have selected Payment. \n";
        cout << "\nPayment: ";

        break;
    case 5:
        system("cls");
        cout << "=============================================\n";
        cout << "|           Welcome to Le Fang ATM          |\n";
        cout << "=============================================\n\n";
        cout << "\tYou have selected Receipt. \n";
        cout << "\nReceipt: ";

        break;
    case 6:
        cout << "Thank you for using Le Fang ATM. Goodbye!\n";
        exit(0);
    }
}

void Account::waitForUser()
{
    // for waiting user such as invalid or retry
    cout << "Press Enter To Continue....";
    cin.get();
}
