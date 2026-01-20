#include <iostream>
#include <limits>
#include "Screen/Screen.hpp"
#include "utils/Login/Login.hpp"
#include "utils/Account/Account.hpp"
#include "utils/Payment/Payment.hpp"
#include "utils/CreateAccount/CreateAccount.hpp"

using namespace std;

int main()
{
    system("cls");
    Screen currentScreen = Screen::MAIN_MENU;

    Login login;
    CreateAccount createAccount;
    Account account;
    Payment Payment;

    while (true)
    {
        switch (currentScreen)
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
                currentScreen = Screen::MAIN_MENU;
                break;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (option == 1)
                currentScreen = Screen::LOGIN;
            else if (option == 2)
                currentScreen = Screen::CREATE_ACCOUNT_MENU;
            else if (option == 3)
                currentScreen = Screen::EXIT;
            else
            {
                cout << "Please Select options 1-3 only.\n";
                account.waitForUser();
                Screen::MAIN_MENU;
            }
            break;

        // If user pressed 1 will go to login screen
        case Screen::LOGIN:
        {
            currentScreen = login.loginMenu();
            account.setCurrentUser(login.getUserName(), login.getPIN());
            break;
        }

        case Screen::ACCOUNT_MENU:
            currentScreen = account.accountMenu();
            break;

        case Screen::Payment_MENU:
            currentScreen = Payment.paymentMenu();
            break;

        // If user pressed 2 will go to Create Account Menu screen
        case Screen::CREATE_ACCOUNT_MENU:
            currentScreen = createAccount.createAccountMenu();
            break;

        // If user pressed 3 will go to Exit screen
        case Screen::EXIT:
            cout << "Thank you for using Le Fang ATM. Goodbye !\n";
            return 0;
        }
    }
}