#include <iostream>
#include <iomanip>
#include <limits>
#include "CreateAccount.hpp"

using namespace std;

// set constructor default id, balance of USD and KHR = 0
CreateAccount::CreateAccount()
{
    id = 0;
    balanceUSD = 0;
    balanceKHR = 0;
}

Screen CreateAccount::createAccountMenu()
{
    system("cls");
    cout << "==============================================\n"
         << "|             Creating an account            |\n"
         << "==============================================\n\n";
    cout << "\tPlease select your account type.\n";
    cout << "\t1) Create account\n";
    cout << "\t2) Go back\n";
    cout << "\t3) Exit ATM\n";
    cout << "\n\tPlease select: ";

    cin >> createAccOption;
    switch (createAccOption)
    {
    case 1:
        system("cls");
        cout << "==============================================\n"
             << "|             Creating an account            |\n"
             << "==============================================\n";
        cout << "Please fill in the required fills.\n\n";

        cout << "Enter your username: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, userName);

        cout << "Enter your PIN (4 digits): ";
        getline(cin, pin);

        // Validation
        if (!isValidPIN(pin))
        {
            cout << "Invalid PIN, Must be exactly 4 digits.\n";
            waitForUser();
            return Screen::CREATE_ACCOUNT_MENU;
        }

        // Insert into DB
        if (!createAccount(userName, pin))
        {
            cout << "Account creation failed. User name may exist.\n";
            waitForUser();
            // if user name exist or fail it will back to create account menu
            return Screen::CREATE_ACCOUNT_MENU;
        }

        // Direct to Login screen after successfully created
        cout << "Accout created successfully.\n";
        waitForUser();
        return Screen::LOGIN;

    case 2:
        cout << "Go back to main menu \n";
        waitForUser();
        return Screen::MAIN_MENU;

    case 3:
        system("cls");
        cout << "Thank you for visiting Le Fang ATM Service";
        exit(0);

    default:
        cout << "Please Select options 1-3 only.\n";
        waitForUser();
        return Screen::CREATE_ACCOUNT_MENU;
    };

    waitForUser();
    return Screen::CREATE_ACCOUNT_MENU;
}

// validate PIN (must be exactly 4 digits)
bool CreateAccount::isValidPIN(const string &pin)
{
    if (pin.length() != 4)
        return false;

    // loop over each digit, if not digit return false
    for (char c : pin)
    {
        if (!isdigit(c))
            return false;
    }

    return true;
}

// Insert data into db
bool CreateAccount::createAccount(const string &userName, const string &pin)
{
    // first we open db (atm.db) in data directory
    if (!db.open("atm.db"))
        return false;

    // declared sql varaible and write SQL logic
    string newAccount =
        "INSERT INTO Account (username, pin) VALUES ('" + userName + "','" + pin + "');";

    // Save to db
    bool success = db.execute(newAccount);

    // Close db;
    db.close();

    return success;
}
