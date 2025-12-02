#include <iostream>
#include "utils/login/login.hpp"
#include "utils/createAccount/createAccount.hpp"
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
        cout << " => Press 1 for Yes\n";
        cout << " => Press 2 for No\n";
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
        }
        break;
    }

    return 0;
}
