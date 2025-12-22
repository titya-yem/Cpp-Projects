#include <iostream>
#include <fstream>
#include <limits>
#include <string>

using namespace std;

struct Account
{
    string userName;
    int password;
};

void saveAccount()
{
    ofstream dataFile("data.csv", ios::app);
    if (dataFile.is_open())
    {
        Account newAccount;

        cout << "========================================\n";
        cout << "|     Please Enter your information     |\n";
        cout << "========================================\n";

        cout << "Enter your username: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, newAccount.userName);

        // Password input with validation
        cout << "Enter a 4-digit password: ";
        cin >> newAccount.password;

        while (newAccount.password < 1000 || newAccount.password > 9999)
        {
            cout << "Invalid! Password must be exactly 4 digits.\n";
            cout << "Enter a 4-digit password: ";
            cin >> newAccount.password;
        }

        // Display result
        system("cls");
        cout << "\nAccount created successfully!\n";
        cout << "========================================\n";
        cout << "|         Your account details         |\n";
        cout << "========================================\n";
        cout << " Username: " << newAccount.userName << endl;
        cout << " Password: " << newAccount.password << endl;

        dataFile << newAccount.userName << "," << newAccount.password << endl;
        dataFile.close();
    }
}