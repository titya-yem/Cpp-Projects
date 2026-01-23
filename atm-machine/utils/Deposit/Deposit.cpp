#include "Deposit.hpp"
#include <limits>
#include "../../config/Database.hpp"

using namespace std;

Screen Deposit::depositMenu()
{
    system("cls");
    cout << "===============================================\n"
         << "|                 Deposit Menu                |\n"
         << "===============================================\n";
    cout << "   Please select your options for deposit \n\n";
    cout << "\t1) Deposit" << "\t2) Go back \n"
         << "\t\t 3) Exit\n";
    cout << "\nEnter your choice: ";

    cin >> depositOption;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (depositOption)
    {
    case 1:
    {
        system("cls");
        cout << "===========================================\n"
             << "|                 Deposit                 |\n"
             << "===========================================\n";
        cout << "NOTE: if amount not entered or 0.\n"
             << "      It will not be added.\n\n ";

        cout << "\tDeposit USD amount: ";
        cin >> depositUSD;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\tDeposit KHR amount: ";
        cin >> depositKHR;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (depositUSD < 0 || depositKHR < 0)
        {
            cout << "Invalid deposit amount.\n";
            waitForUser();
            return Screen::Deposit_Menu;
        }

        if (depositUSD == 0 && depositKHR == 0)
        {
            cout << "No deposit amount entered.\n";
            waitForUser();
            return Screen::Deposit_Menu;
        }

        // Open DB
        Database db;
        if (!db.open("atm.db"))
        {
            cout << "Database error.\n";
            waitForUser();
            return Screen::Deposit_Menu;
        }

        sqlite3 *conn = db.getDB();
        sqlite3_stmt *stmt;

        sqlite3_exec(conn, "BEGIN TRANSACTION;", nullptr, nullptr, nullptr);

        // Fetch current balances
        const char *sql = "SELECT BalanceUSD, BalanceKHR FROM Account WHERE username = ? AND pin = ?;";
        if (sqlite3_prepare_v2(conn, sql, -1, &stmt, nullptr) != SQLITE_OK)
        {
            sqlite3_exec(conn, "ROLLBACK;", nullptr, nullptr, nullptr);
            cout << "Failed to prepare SELECT statement.\n";
            waitForUser();
            return Screen::Deposit_Menu;
        }

        sqlite3_bind_text(stmt, 1, userName.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, pin.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            currentUSD = sqlite3_column_double(stmt, 0);
            currentKHR = sqlite3_column_double(stmt, 1);
        }
        else
        {
            sqlite3_exec(conn, "ROLLBACK;", nullptr, nullptr, nullptr);
            cout << "Account not found.\n";
            sqlite3_finalize(stmt);
            waitForUser();
            return Screen::Deposit_Menu;
        }

        sqlite3_finalize(stmt);

        // Calculate new balances
        newDepositUSD = currentUSD + (depositUSD > 0 ? depositUSD : 0);
        newDepositKHR = currentKHR + (depositKHR > 0 ? depositKHR : 0);

        // Update DB
        const char *updateSQL = "UPDATE Account SET BalanceUSD = ?, BalanceKHR = ? WHERE username = ? AND pin = ?;";
        if (sqlite3_prepare_v2(conn, updateSQL, -1, &stmt, nullptr) != SQLITE_OK)
        {
            sqlite3_exec(conn, "ROLLBACK;", nullptr, nullptr, nullptr);
            cout << "Failed to prepare UPDATE statement.\n";
            waitForUser();
            return Screen::Deposit_Menu;
        }

        sqlite3_bind_double(stmt, 1, newDepositUSD);
        sqlite3_bind_double(stmt, 2, newDepositKHR);
        sqlite3_bind_text(stmt, 3, userName.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, pin.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) != SQLITE_DONE)
        {
            sqlite3_exec(conn, "ROLLBACK;", nullptr, nullptr, nullptr);
            cout << "Deposit failed.\n";
            sqlite3_finalize(stmt);
            waitForUser();
            return Screen::Deposit_Menu;
        }

        sqlite3_finalize(stmt);
        sqlite3_exec(conn, "COMMIT;", nullptr, nullptr, nullptr);
        db.close();

        // update currentUSD and KHR = newUSD and KHR after calcuated
        currentUSD = newDepositUSD;
        currentKHR = newDepositKHR;

        // Add receipt record
        receipt->action("Deposit", currentUSD, currentKHR);

        // Show success screen
        return showDepositSuccessful();
    }

    case 2:
        return Screen::ACCOUNT_Menu;

    case 3:
        system("cls");
        cout << "Thank you for using Le Fang ATM. Goodbye!\n";
        exit(0);

    default:
        cout << "Please Select options 1-3 only.\n";
        waitForUser();
        return Screen::Deposit_Menu;
    }
}

Screen Deposit::showDepositSuccessful()
{
    system("cls");
    cout << "===============================================\n"
         << "|              Deposit successful             |\n"
         << "===============================================\n";
    cout << "\tTotal USD Balance: " << currentUSD << " $\n";
    cout << "\tTotal KHR Balance: " << currentKHR << " reil\n\n";

    cout << "\tDeposit USD Balance: " << depositUSD << " $\n";
    cout << "\tDeposit KHR Balance: " << depositKHR << " reil\n";
    cout << "===============================================\n";
    cout << "\t1) Go back " << "\t 2) Exit\n";
    cout << "\tEnter your choice: ";

    cin >> depositSuccessfulOption;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (depositSuccessfulOption)
    {
    case 1:
        cout << "Go back to Account Menu. \n";
        waitForUser();
        return Screen::ACCOUNT_Menu;

    case 2:
        system("cls");
        cout << "Thank you for using Le Fang ATM. Goodbye!\n";
        exit(0);

    default:
        cout << "Please select options 1-2 only.\n";
        waitForUser();
        return Screen::Deposit_Menu;
    }
}

Deposit::Deposit(Receipt *receipt)
{
    this->receipt = receipt;
}
