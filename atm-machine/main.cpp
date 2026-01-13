#include <iostream>
#include "utils/Login/Login.hpp"
#include "utils/CreateAccount/CreateAccount.hpp"

using namespace std;

int main()
{
    system("cls");
    while (true)
    {
        cout << "===============================================\n";
        cout << "|            Welcome to Le Fang ATM           |\n";
        cout << "===============================================\n\n";
        cout << "\tDo you have accounts or not ?\n";
        cout << "\t1) Yes (Login)\n";
        cout << "\t2) No (Create Account)\n";
        cout << "\t3) Exit ATM\n";
        cout << "\n\tPlease select: ";

        short choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Login loginAccount;
            loginAccount.loginAccount();
            break;
        }
        case 2:
            CreateAccount CreateAccount;
            CreateAccount.createAccountMenu();
            break;
        case 3:
            cout << "Thank you for using Le Fang ATM. Goodbye !";
            exit(0);
        default:
            system("cls");
            cout << "Please Select options 1-3 only.\n";
        }
    }

    return 0;
}
