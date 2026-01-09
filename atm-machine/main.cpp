#include <iostream>

using namespace std;

int main()
{
    system("cls");

    cout << "\t========================================\n";
    cout << "\t|        Welcome to Le Fang ATM        |\n";
    cout << "\t========================================\n\n";
    cout << " \tDo you have accounts or not ? \n";
    cout << " \t1) Yes (Login)\n";
    cout << " \t2) No (Create Account)\n";
    cout << " \t3) Exit ATM\n";
    cout << " \tPlease select: ";

    short choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Login";
        break;
    case 2:
        cout << "Create Account";
        break;
    case 3:
        cout << "Thank you for using Le Fang ATM. Goodbye !";
        exit(0);
    }

    return 0;
}
