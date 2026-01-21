#include <iostream>
#include <limits>
#include "Screen/Screen.hpp"
#include "utils/Login/Login.hpp"
#include "utils/Account/Account.hpp"
#include "utils/Payment/Payment.hpp"
#include "utils/CreateAccount/CreateAccount.hpp"
#include "utils/Deposit/Deposit.hpp"

using namespace std;

int main()
{
    system("cls");
    Screen currentScreen = Screen::MAIN_Menu;

    Login login;
    CreateAccount createAccount;
    Account account;
    Payment Payment;
    Deposit deposit;

    while (true)
    {
        switch (currentScreen)
        {
        case Screen::MAIN_Menu:
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
                currentScreen = Screen::MAIN_Menu;
                break;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (option == 1)
                currentScreen = Screen::LOGIN;
            else if (option == 2)
                currentScreen = Screen::CREATE_ACCOUNT_Menu;
            else if (option == 3)
                currentScreen = Screen::EXIT;
            else
            {
                cout << "Please Select options 1-3 only.\n";
                account.waitForUser();
                Screen::MAIN_Menu;
            }
            break;

        // If user pressed 1 will go to login screen
        case Screen::LOGIN:
        {
            currentScreen = login.loginMenu();
            // using account's method (setCurrentUser) to get values
            // get userName & PIN from login (getters)
            account.setCurrentUser(login.getUserName(), login.getPIN());
            break;
        }

        // Each display screens
        case Screen::ACCOUNT_Menu:
            currentScreen = account.accountMenu();
            break;

        case Screen::Payment_Menu:
            currentScreen = Payment.paymentMenu();
            break;

        case Screen::Deposit_Menu:
            currentScreen = deposit.depositMenu();
            break;
        // End of display screen

        // If user pressed 2 will go to Create Account Menu screen
        case Screen::CREATE_ACCOUNT_Menu:
            currentScreen = createAccount.createAccountMenu();
            break;

        // If user pressed 3 will go to Exit screen
        case Screen::EXIT:
            cout << "Thank you for using Le Fang ATM. Goodbye !\n";
            exit(0);
        }
    }
    return 0;
}