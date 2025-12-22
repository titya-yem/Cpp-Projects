#include <iostream>
#include "login/login.hpp"
#include "createAccount/createAccount.hpp"
using namespace std;

int main()
{
    system("cls");

    while (true)
    {
        cout << "=============================================\n";
        cout << "|           Welcome to Le Fang ATM          |\n";
        cout << "=============================================\n\n";
        cout << "Do you have an account?\n";
        cout << " 1) Press 1 for Yes\n";
        cout << " 2) Press 2 for No\n";
        cout << " 3) Press 3 for Exit\n";
        cout << "\nEnter your choice: ";

        short choice;
        cin >> choice;
        system("cls");

        switch (choice)
        {
        case 1:
            LoginUser();
            break;
        case 2:
            createAccount();
            break;
        case 3:
            cout << "Thank you for visiting Le Fang ATM Service";
            break;
        }
        break;
    }

    return 0;
}
