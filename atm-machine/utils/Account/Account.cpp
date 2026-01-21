#include "Account.hpp"
#include <limits>
#include <algorithm>
#include <cctype>
#include <iostream>
#include "../../config/Database.hpp"

Screen Account::accountMenu()
{
    system("cls");
    cout << "===============================================\n";
    cout << "|                 Account Menu                |\n";
    cout << "===============================================\n\n";
    cout << "      Please select your prefer options \n";
    cout << " 1) Account" << "\t2) Balance" << "\t3) Transaction\n"
         << " 4) Payment" << "\t5) Receipt" << "\t6) Exit\n";
    cout << "\nEnter your choice: ";

    cin >> accountOption;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch (accountOption)
    {
    case 1:
    {
        system("cls");
        // Show account info
        Database db;
        if (!db.open("atm.db"))
        {
            cout << "Database error. \n";
            waitForUser();
            return Screen::ACCOUNT_MENU;
        }

        // SQL with placeholders to query data from atm.db
        const char *sql =
            "SELECT id, username, pin, BalanceUSD, BalanceKHR "
            "FROM Account WHERE username = ? AND pin = ?;";

        sqlite3_stmt *stmt;
        sqlite3 *conn = db.getDB();

        if (sqlite3_prepare_v2(conn, sql, -1, &stmt, nullptr) != SQLITE_OK)
        {
            cout << "Prepare failed\n";
            return Screen::ACCOUNT_MENU;
        }

        // Bind values safely (prevents SQL injection)
        sqlite3_bind_text(stmt, 1, userName.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, pin.c_str(), -1, SQLITE_STATIC);

        // create data array to store info
        accountInformation data{};
        bool loginSuccess = false;

        if (sqlite3_step(stmt) == SQLITE_ROW) // row exists
        {
            loginSuccess = true;

            // assign value by indexs of data array
            data.id = sqlite3_column_int(stmt, 0);
            data.userName = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            data.pin = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
            data.balanceUSD = sqlite3_column_double(stmt, 3);
            data.balanceKHR = sqlite3_column_double(stmt, 4);
        }

        // clean memory and close db
        sqlite3_finalize(stmt);
        db.close();

        if (loginSuccess)
        {
            return accountData(data);
        }
        else
        {
            cout << "Invalid username or PIN\n";
            waitForUser();
            return Screen::ACCOUNT_MENU;
        }

        break;
    }
    case 2:
        return Screen::Balance_MENU;
        break;

    case 3:
        return Screen::Transaction_MENU;
        break;

    case 4:
        return Screen::Payment_MENU;
        break;

    case 5:
        return Screen::Receipt_MENU;
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

Screen Account::accountData(accountInformation &data)
{
    cout << "================================================\n"
         << "|              Account Information             |\n"
         << "================================================\n";
    cout << "\tAccount ID: " << ((data.id > 0) ? to_string(data.id) : "___") << endl;
    cout << "\tusername: " << ((data.userName.length() > 0) ? data.userName : "___") << endl;
    cout << "\tPIN: " << ((data.pin.length() == 4) ? data.pin : "___") << endl;
    cout << "\tBalance in USD: " << data.balanceUSD << " $" << endl;
    cout << "\tBalance in KHR: " << data.balanceKHR << " reil" << endl;
    cout << "================================================\n";
    cout << "\t1) Go back"
         << "\t2) Exit \n";
    cout << "\tPlease select your option: ";

    cin >>
        accountInformationOption;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch (accountInformationOption)
    {
    case 1:
        cout << "Go back to Account Menu\n";
        waitForUser();
        return Screen::ACCOUNT_MENU;
        break;
    case 2:
        cout << "Thank you for using Le Fang ATM. Goodbye!\n";
        exit(0);
        break;
    default:
        cout << "Please Select options 1-2 only.\n";
        waitForUser();
        break;
    }

    waitForUser();
    return Screen::ACCOUNT_MENU;
}

void Account::setCurrentUser(const string &userName, const string &pin)
{
    // We pass userName and Pin from LoginMenu to Main.cpp
    // get those values from Main.cpp and assign them here
    // set Logged-in userName & pin from Login Menu to Account Menu
    this->userName = userName;
    this->pin = pin;
}

void Account::waitForUser()
{
    // for waiting user such as invalid or retry
    cout << "Press Enter To Continue....";
    cin.get();
}
