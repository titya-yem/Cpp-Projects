#include "Account.hpp"

void Account::mainMenu()
{
    system("cls");
    // Allow user to select card type and enter PIN again and again
    while (true)
    {
        // if possible fetch userName from db and shows here.
        cout << "===============================================\n";
        cout << "|            Welcome to Le Fang ATM           |\n";
        cout << "===============================================\n\n";
        cout << "\tPlease select your options: \n";
        cout << "\t1) Account" << "\t2) Balance" << "\t3) Transaction\n"
             << "\t4) Payment" << "\t5) Receipt" << "\t6) Exit\n";
        cout << "\n\tEnter your choice: ";

        cin >> menuOption;
        system("cls");

        switch (menuOption)
        {
        case 1:
            cout << "===============================================\n";
            cout << "|            Welcome to Le Fang ATM           |\n";
            cout << "===============================================\n\n";
            cout << "\tYou have selected Account. \n";
            cout << "\n\tAccount";

            break;
        case 2:
            cout << "===============================================\n";
            cout << "|            Welcome to Le Fang ATM           |\n";
            cout << "===============================================\n\n";
            cout << "\tYou have selected Balance. \n";
            cout << "\n\nBalance: ";

            break;
        case 3:
            cout << "=============================================\n";
            cout << "|           Welcome to Le Fang ATM          |\n";
            cout << "=============================================\n\n";
            cout << "\tYou have selected Transaction. \n";
            cout << "\n\n: ";

            break;
        case 4:
            cout << "=============================================\n";
            cout << "|           Welcome to Le Fang ATM          |\n";
            cout << "=============================================\n\n";
            cout << "\tYou have selected Payment. \n";
            cout << "\n\n: Payment";

            break;
        case 5:
            cout << "=============================================\n";
            cout << "|           Welcome to Le Fang ATM          |\n";
            cout << "=============================================\n\n";
            cout << "\tYou have selected Receipt. \n";
            cout << "\n\n: Receipt";

            break;
        case 6:
            cout << "Thank you for using Le Fang ATM. Goodbye!\n";
            exit(0);
        }
    }
}
