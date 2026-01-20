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

    cin >> menuOption;
    switch (menuOption)
    {
    case 1:
    {
        system("cls");

        Database db;
        if (!db.open("atm.db"))
        {
            cout << "Database error. \n";
            waitForUser();
            return Screen::ACCOUNT_MENU;
        }

        const char *sql =
            "SELECT * FROM Account WHERE id = ?;";

        sqlite3_stmt *stmt;
        sqlite3 *conn = db.getDB();

        if (sqlite3_prepare_v2(conn, sql, -1, &stmt, nullptr) != SQLITE_OK)
        {
            cout << "SQL prepare failed. \n";
            db.close();
            waitForUser();
            return Screen::ACCOUNT_MENU;
        }

        sqlite3_bind_text(stmt, 1, userName.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, pin.c_str(), -1, SQLITE_STATIC);

        bool loginSuccess = false;

        if (sqlite3_step(stmt) == SQLITE_ROW)
            loginSuccess = true;

        sqlite3_finalize(stmt);
        db.close();

        if (loginSuccess)
        {
            // must pass fetch data from sqlite as parameter
            // accountData();
        }
        else
        {
            // must pass incorrect data from sqlite as parameter
            // accountData();
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
    cin >> menuOption;
    switch (menuOption)
    {
    case 1:
        cout << "================================================\n"
             << "|              Account Information             |\n"
             << "================================================\n\n";
        cout << "\tYour Account ID: " << ((data.id > 0) ? to_string(data.id) : "___") << endl;
        cout << "\tYour username: " << data.userName << endl;
        cout << "\tYour PIN: " << data.pin << endl;
        cout << "\tBalance in USD: " << data.balanceUSD << endl;
        cout << "\tBalance in KHR: " << data.balanceKHR << endl;
        cout << "\tGo back to Main Menu\n";
        cout << "\tExit \n";
    case 2:
        cout << "Go back to Main Menu";
        waitForUser();
        return Screen::MAIN_MENU;
    case 3:
        cout << "Thank you for using Le Fang ATM. Goodbye!\n";
        exit(0);
    default:
        cout << "Please Select options 1-3 only.\n";
        waitForUser();
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
