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

        Database db;
        if (!db.open("atm.db"))
        {
            cout << "Database error. \n";
            waitForUser();
            return Screen::ACCOUNT_MENU;
        }

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

        sqlite3_bind_text(stmt, 1, userName.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, pin.c_str(), -1, SQLITE_STATIC);

        accountInformation data{};
        bool loginSuccess = false;

        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            loginSuccess = true;

            data.id = sqlite3_column_int(stmt, 0);
            data.userName = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            data.pin = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
            data.balanceUSD = sqlite3_column_double(stmt, 3);
            data.balanceKHR = sqlite3_column_double(stmt, 4);
        }

        sqlite3_finalize(stmt);
        db.close();

        if (loginSuccess)
            accountData(data);
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
    cin >> accountInformationOption;
    switch (accountInformationOption)
    {
    case 1:
        cout << "================================================\n"
             << "|              Account Information             |\n"
             << "================================================\n\n";
        cout << "\tYour Account ID: " << ((data.id > 0) ? to_string(data.id) : "___") << endl;
        cout << "\tYour username: " << ((data.userName.length() > 0) ? data.userName : "___") << endl;
        cout << "\tYour PIN: " << ((data.pin.length() == 4) ? data.pin : "___") << endl;
        cout << "\tBalance in USD: " << data.balanceUSD << " $" << endl;
        cout << "\tBalance in KHR: " << data.balanceKHR << " reil" << endl;
        cout << "\tGo back to Main Menu\n";
        cout << "\tExit \n";

        break;
    case 2:
        cout << "Go back to Main Menu";
        waitForUser();
        return Screen::MAIN_MENU;
        break;
    case 3:
        cout << "Thank you for using Le Fang ATM. Goodbye!\n";
        exit(0);
        break;
    default:
        cout << "Please Select options 1-3 only.\n";
        waitForUser();
        break;
    }

    waitForUser();
    return Screen::ACCOUNT_MENU;
}

void Account::setCurrentUser(const string &userName, const string &pin)
{
    this->userName = userName;
    this->pin = pin;
}

void Account::waitForUser()
{
    // for waiting user such as invalid or retry
    cout << "Press Enter To Continue....";
    cin.get();
}
