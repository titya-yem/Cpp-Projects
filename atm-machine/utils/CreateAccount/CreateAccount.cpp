#include <iostream>
#include <iomanip>
#include "CreateAccount.hpp"

using namespace std;

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

        cout << "Enter your userName: ";
        getline(cin, userName);

        cout << "Enter your PIN (4 digits): ";
        getline(cin, pin);

        // Validation
        if (!isValidPIN(pin))
        {
            cout << "Invalid PIN, Must be exactly 4 digits.\n";
            return Screen::CREATE_ACCOUNT_MENU;
        }

        // Insert into DB
        if (!insertAccount(userName, pin))
        {
            cout << "Account creation failed. Username may exist.\n";
            return Screen::CREATE_ACCOUNT_MENU;
        }

        cout << "Accout created successfully.\n";
        return Screen::ACCOUNT_MENU;
    case 2:
        cout << "Go back to main menu";
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

// Insert new account into Database
bool CreateAccount::insertAccount(const string &userName, const string &pin)
{
    // first we open db (atm.db)
    db.open("atm.db");

    // declared sql varaible and write SQL logic
    string sql =
        "INSERT INTO accounts (userName, pin_hash) VALUE ('" + userName + "', '" + pin + "');";

    // return db execution;
    return db.execute(sql);
}
