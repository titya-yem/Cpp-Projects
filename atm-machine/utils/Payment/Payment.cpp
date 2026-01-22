#include "Payment.hpp"
#include <limits>

using namespace std;

Screen Payment::paymentMenu()
{
    system("cls");
    cout << "=============================================\n"
         << "|                Payment Menu               |\n"
         << "=============================================\n";
    cout << "   Please select your options for payment \n\n";
    cout << "\t1) Payment" << "\t2) Go back\n"
         << "\t\t  3) Exit";
    cout << "\nEnter your choice: ";

    cin >> paymentMenuOption;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch (paymentMenuOption)
    {
    case 1:
    {
        system("cls");
        cout << "============================================\n"
             << "|                  Payment                 |\n"
             << "============================================\n";
        cout << "NOTE: if amount not entered or 0.\n"
             << "      It will not be added.\n\n";

        cout << "Payment USD amount: ";
        cin >> paymentInUSD;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Payment KHR amount: ";
        cin >> paymentInKHR;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (paymentInUSD < 0 || paymentInKHR < 0)
        {
            cout << "Invalid payment amount.\n";
            waitForUser();
            return Screen::Payment_Menu;
        }

        Database db;
        if (!db.open("atm.db"))
        {
            cout << "Database error.\n";
            waitForUser();
            return Screen::Payment_Menu;
        }

        sqlite3 *conn = db.getDB();
        sqlite3_stmt *stmt;

        // start transaction
        sqlite3_exec(conn, "BEGIN TRANSACTION;", nullptr, nullptr, nullptr);

        // Get current balance
        const char *sql =
            "SELECT BalanceUSD, BalanceKHR FROM Account "
            "WHERE username = ? AND pin = ?;";

        // after fetching balance
        if (sqlite3_prepare_v2(conn, sql, -1, &stmt, nullptr) != SQLITE_OK)
        {
            sqlite3_exec(conn, "ROLLBACK;", nullptr, nullptr, nullptr);
            cout << "Failed to prepare SELECT statement.\n";
            waitForUser();
            return Screen::Payment_Menu;
        }

        sqlite3_bind_text(stmt, 1, userName.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, pin.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            currentBalanceInUSD = sqlite3_column_double(stmt, 0);
            currentBalanceInKHR = sqlite3_column_double(stmt, 1);
        }
        else
        {
            cout << "Account not found,\n";
            sqlite3_finalize(stmt);
            sqlite3_exec(conn, "ROLLBACK", nullptr, nullptr, nullptr);
            waitForUser();
            return Screen::Payment_Menu;
        }

        sqlite3_finalize(stmt);

        if ((paymentInUSD > 0 && paymentInUSD > currentBalanceInUSD) ||
            (paymentInKHR > 0 && paymentInKHR > currentBalanceInKHR))
        {
            sqlite3_exec(conn, "ROLLBACK;", nullptr, nullptr, nullptr);
            cout << "Insufficient balance.\n";
            waitForUser();
            return Screen::Payment_Menu;
        }

        // Calculate new payment (-) to the current balance
        newPaymentUSD = currentBalanceInUSD - (paymentInUSD > 0 ? paymentInUSD : 0);
        newPaymentKHR = currentBalanceInKHR - (paymentInKHR > 0 ? paymentInKHR : 0);

        // update BalanceUSD and BalanceKHR
        const char *updateSQL =
            "UPDATE Account SET BalanceUSD = ?, BalanceKHR = ? "
            "WHERE username = ? AND pin = ?;";
        if (sqlite3_prepare_v2(conn, updateSQL, -1, &stmt, nullptr) != SQLITE_OK)
        {
            sqlite3_exec(conn, "ROLLBACK", nullptr, nullptr, nullptr);
            cout << "Failed to prepare UPDATE statnent.\n";
            waitForUser();
            return Screen::Payment_Menu;
        }

        sqlite3_bind_double(stmt, 1, newPaymentUSD);
        sqlite3_bind_double(stmt, 2, newPaymentKHR);
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
        currentBalanceInUSD = newPaymentUSD;
        currentBalanceInKHR = newPaymentKHR;

        return showPaymentSuccessful();
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
        return Screen::Payment_Menu;
        break;
    }

    waitForUser();
    return Screen::Payment_Menu;
}

Screen Payment::showPaymentSuccessful()
{
    system("cls");
    cout << "===============================================\n"
         << "|              Payment successful             |\n"
         << "===============================================\n";
    cout << "\tTotal USD Balance: " << currentBalanceInUSD << " $\n";
    cout << "\tTotal KHR Balance: " << currentBalanceInKHR << " reil\n\n";

    cout << "\tPayment USD Balance: " << paymentInUSD << " $\n";
    cout << "\tPayment KHR Balance: " << paymentInKHR << " reil\n";
    cout << "===============================================\n";
    cout << "\t1) Go back " << "\t 2) Exit\n";
    cout << "\tEnter your choice: ";

    cin >> paymentSuccessfulOption;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (paymentSuccessfulOption)
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
