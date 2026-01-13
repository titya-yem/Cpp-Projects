#include <iostream>
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

    while (current != Screen::EXIT)
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
            current = (option == 1)   ? Screen::LOGIN
                      : (option == 2) ? Screen::CREATE_ACCOUNT_MENU
                      : (option == 3) ? Screen::EXIT
                                      : Screen::MAIN_MENU;
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
            cout << "Thank you for using Le Fang ATM. Goodbye !";
            exit(0);

        // If user pressed invalid numbers will go to Main Menu screen
        default:
            system("cls");
            cout << "Please Select options 1-3 only.\n";
            account.waitForUser();
        }
    }

    return 0;
}