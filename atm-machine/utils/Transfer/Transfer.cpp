#include "Transfer.hpp"
#include <limits>

Screen Transfer::transferMenu()
{
    system("cls");
    cout << "=============================================\n";
    cout << "|                  Transfer                 |\n";
    cout << "=============================================\n";
    cout << "   Please select your options for transfer \n\n";
    cout << "\t1) Transfer" << "\t2) Go back \n"
         << "  \t\t3) Exit\n";
    cout << "\nEnter your choice: ";

    cin >> transferMenuOption;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch (transferMenuOption)
    {
    case 1:
    {
        system("cls");
        cout << "=============================================\n"
             << "|                  Transfer                 |\n"
             << "=============================================\n";
        cout << "NOTE: if amount not entered or 0.\n"
             << "      It will not be added.\n\n";

        cout << "Transfer USD amount: ";
        cin >> transferInUSD;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Transfer KHR amount: ";
        cin >> transferInKHR;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (transferInUSD < 0 || transferInKHR < 0)
        {
            cout << "Invalid transfer amount";
            waitForUser();
            return Screen::Transfer_Menu;
        }

        Database db;
        if (!db.open("atm.db"))
        {
            cout << "Database error.\n";
            waitForUser();
            return Screen::Transfer_Menu;
        }

        sqlite3 *conn = db.getDB();
        sqlite3_stmt *stmt;

        // start transfer
        sqlite3_exec(conn, "BEGIN TRANSFER;", nullptr, nullptr, nullptr);

        // get current balance
        const char *sql =
            "SELECT BalanceUSD, BalanceKHR FROM Account "
            "WHERE username = ? AND pin = ?;";

        // after fetching balance
        if (sqlite3_prepare_v2(conn, sql, -1, &stmt, nullptr) != SQLITE_OK)
        {
            sqlite3_exec(conn, "ROLLBACK;", nullptr, nullptr, nullptr);
            cout << "Failed to prepare SELECT statement.\n";
            waitForUser();
            return Screen::Transfer_Menu;
        }

        sqlite3_bind_text(stmt, 1, userName.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, pin.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            currentBlanceInUSD = sqlite3_column_double(stmt, 0);
            currentBlanceInKHR = sqlite3_column_double(stmt, 1);
        }
        else
        {
            cout << "Account not found,\n";
            sqlite3_finalize(stmt);
            sqlite3_exec(conn, "ROLLBACK", nullptr, nullptr, nullptr);
            waitForUser();
            return Screen::Transfer_Menu;
        }

        sqlite3_finalize(stmt);

        if ((transferInUSD > 0 && transferInUSD > currentBlanceInUSD) ||
            (transferInKHR > 0 && transferInKHR > currentBlanceInKHR))
        {
            sqlite3_exec(conn, "ROLLBACK;", nullptr, nullptr, nullptr);
            cout << "Insufficient balance.\n";
            waitForUser();
            return Screen::Transfer_Menu;
        }

        // Calculate new payment (-) to the current balance
        newTransferUSD = currentBlanceInUSD - (transferInUSD > 0 ? transferInUSD : 0);
        newTransferKHR = currentBlanceInKHR - (transferInKHR > 0 ? transferInUSD : 0);

        // update BalanceUSD and BalanceKHR
        const char *updateSQL =
            "UPDATE Account SET BalanceUSD = ?, BalanceKHR = ? "
            "WHERE username = ? AND pin = ?;";
        if (sqlite3_prepare_v2(conn, updateSQL, -1, &stmt, nullptr) != SQLITE_OK)
        {
            sqlite3_exec(conn, "ROLLBACK", nullptr, nullptr, nullptr);
            cout << "Failed to prepare UPDATE statnent.\n";
            waitForUser();
            return Screen::Transfer_Menu;
        }

        sqlite3_bind_double(stmt, 1, newTransferUSD);
        sqlite3_bind_double(stmt, 2, newTransferKHR);
        sqlite3_bind_text(stmt, 3, userName.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, pin.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) != SQLITE_DONE)
        {
            cout << "Payment failed.\n";
            sqlite3_exec(conn, "ROLLBACK", nullptr, nullptr, nullptr);
            sqlite3_finalize(stmt);
            waitForUser();
            return Screen::Payment_Menu;
        }

        sqlite3_finalize(stmt);
        sqlite3_exec(conn, "COMMIT", nullptr, nullptr, nullptr);
        db.close();

        // update current
        currentBlanceInUSD = newTransferUSD;
        currentBlanceInKHR = newTransferKHR;

        return showTransferSuccessful();

        break;
    }
    case 2:
        cout << "Go back to Account Menu\n";
        waitForUser();
        return Screen::ACCOUNT_Menu;
        break;
    case 3:
        system("cls");
        cout << "Thank you for using Le Fang ATM. Goodbye!\n";
        exit(0);
        break;
    default:
        cout << "Please Select options 1-3 only.\n";
        waitForUser();
        return Screen::Transfer_Menu;
        break;
    }

    waitForUser();
    return Screen::Transfer_Menu;
}

Screen Transfer::showTransferSuccessful()
{
    system("cls");
    cout << "================================================\n"
         << "|              Transfer successful             |\n"
         << "================================================\n";
    cout << "\tTotal USD Balance: " << currentBlanceInUSD << " $\n";
    cout << "\tTotal KHR Balance: " << currentBlanceInKHR << " reil\n\n";

    cout << "\tPayment USD Balance: " << transferInUSD << " $\n";
    cout << "\tPayment KHR Balance: " << transferInKHR << " reil\n";
    cout << "===============================================\n";
    cout << "\t1) Go back " << "\t 2) Exit\n";
    cout << "\tEnter your choice: ";

    cin >> transferSuccessfulOption;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (transferSuccessfulOption)
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
