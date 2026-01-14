#include <iostream>
#include <limits>
#include "utils/Login/Login.hpp"
#include "utils/CreateAccount/CreateAccount.hpp"
#include "utils/Screen/Screen.hpp"
#include "utils/Account/Account.hpp"

using namespace std;

int main()
{
    system("cls");
    Screen current = Screen::MAIN_MENU;

    Login login;
    CreateAccount createAccount;
    Account account;

    while (true)
    {
        switch (current)
        {
        case Screen::MAIN_MENU:
            system("cls");
            cout << "===============================================\n";
            cout << "|            Welcome to Le Fang ATM           |\n";
            cout << "===============================================\n\n";
            cout << "\tDo you have accounts or not ?\n";
            cout << "\t1) Yes (Login)\n";
            cout << "\t2) No (Create Account)\n";
            cout << "\t3) Exit ATM\n";
            cout << "\n\tPlease select: ";

            short option;
            cin >> option;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter number 1-3 only.\n";
                account.waitForUser();
                current = Screen::MAIN_MENU;
                break;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (option == 1)
                current = Screen::LOGIN;
            else if (option == 2)
                current = Screen::CREATE_ACCOUNT_MENU;
            else if (option == 3)
                current = Screen::EXIT;
            else
            {
                cout << "Please Select options 1-3 only.\n";
                account.waitForUser();
                Screen::MAIN_MENU;
            }
            break;

        // If user pressed 1 will go to login screen
        case Screen::LOGIN:
            current = login.loginAccount();
            break;

        // If user pressed 2 will go to Create Account Menu screen
        case Screen::CREATE_ACCOUNT_MENU:
            current = createAccount.createAccountMenu();
            break;

        // If user pressed 3 will go to Exit screen
        case Screen::EXIT:
            cout << "Thank you for using Le Fang ATM. Goodbye !\n";
            return 0;
        }
    }
}