#include "Account.hpp"
#include <limits>
#include <algorithm>
#include <cctype>
#include "../Screen/Screen.hpp"

Screen Account::mainMenu()
{
    system("cls");
    // will user inheritance when checking the same as function of each of them
    cout << "===============================================\n";
    cout << "|            Welcome to Le Fang ATM           |\n";
    cout << "===============================================\n\n";
    cout << "     Please select your options to check \n";
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

// check input validation
Screen Account::inputValidation(const string &message, const Screen &screen)
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, please select " << message << " numerics only.\n";
        waitForUser();
        return screen;
    }
    return Screen::ACCOUNT_MENU;
}

bool Account::pinValidation(const string &pinToCheck)
{
    if (pinToCheck.length() != 4)
    {
        cout << "Invalid PIN format, Please enter 4 digits only.\n";
        waitForUser();
        return false;
    }

    // check all digits
    for (char c : pinToCheck)
    {
        if (!isdigit(c))
        {
            cout << "Invalid PIN format, Please enter digits only.\n";
            waitForUser();
            return false;
        }
    }

    return true;
}

string Account::trim(const string &s)
{
    size_t start = 0;
    while (start < s.size() && isspace(s[start]))
        start++;
    size_t end = s.size();
    while (end > start && isspace(s[end - 1]))
        end--;
    return s.substr(start, end - start);
}