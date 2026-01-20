#include "Login.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>
#include "../../sqlite/sqlite3.h"
#include "../../config/Database.hpp"

using namespace std;

Screen Login::loginMenu()
{
    system("cls");
    // Allow user to select card type and enter PIN again and again
    cout << "===============================================\n";
    cout << "|            Welcome to Le Fang ATM           |\n";
    cout << "===============================================\n\n";
    cout << "\tPlease select your option: \n";
    cout << "\t1) Login (insert card)\n";
    cout << "\t2) Go back\n";
    cout << "\t3) Exit ATM\n";
    cout << "\n\tEnter your choice: ";

    // validate option
    cin >> option;
    if (cin.fail())
        return inputValidation("1-3", Screen::LOGIN);
    switch (option)
    {
    case 1:
    {
        system("cls");
        cout << "===============================================\n";
        cout << "|                  User Login                 |\n";
        cout << "===============================================\n\n";

        cout << "Enter your username: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, userName);

        cout << "Enter your PIN (4 digits): ";
        getline(cin, pin);

        // validate pin
        if (!pinValidation(pin))
        {
            cout << "Invalid PIN";
            waitForUser();
            return Screen::LOGIN;
        }

        // open database
        Database db;
        if (!db.open("atm.db"))
        {
            cout << "Database error. \n";
            waitForUser();
            return Screen::LOGIN;
        }

        // SQL code (does a row exist with this username AND this pin or not ?)
        const char *sql =
            "SELECT id FROM Account WHERE username = ? AND pin = ?;";

        sqlite3_stmt *stmt;
        sqlite3 *conn = db.getDB();

        // Compile SQL into executable form
        if (sqlite3_prepare_v2(conn, sql, -1, &stmt, nullptr) != SQLITE_OK)
        {
            cout << "SQL prepare failed. \n";
            db.close();
            waitForUser();
            return Screen::LOGIN;
        }

        // Bind user input (replace ? placeholder safely)
        sqlite3_bind_text(stmt, 1, userName.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, pin.c_str(), -1, SQLITE_STATIC);

        // Execute query
        bool loginSucess = false;

        // sqlite3_step runs the SQL
        // If it finds a row -> (SQLITE_ROW)
        // If not -> SQLITE_DONE
        if (sqlite3_step(stmt) == SQLITE_ROW)
            loginSucess = true;

        // cleanup (Very important to cleanup)
        sqlite3_finalize(stmt);
        db.close();

        // Decide result if found or not
        if (loginSucess)
        {
            cout << "Login successful. \n";
            waitForUser();
            setCurrentUser(userName, pin);
            return Screen::ACCOUNT_MENU;
        }
        else
        {
            cout << "Invalid username or password. \n";
            waitForUser();
            return Screen::LOGIN;
        }
    }
    case 2:
        cout << "Going back to Main Menu. \n";
        waitForUser();
        return Screen::MAIN_MENU;

    case 3:
        system("cls");
        cout << "Thank you for using Le Fang ATM. Goodbye!\n";
        exit(0);

    default:
        cout << "Please Select options 1-3 only.\n";
        waitForUser();
        return Screen::LOGIN;
    }

    waitForUser();
    return Screen::LOGIN;
}

// check input validation
Screen Login::inputValidation(const string &message, const Screen &screen)
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, please select " << message << " numerics only.\n";
        waitForUser();
        return screen;
    }
    return Screen::ACCOUNT_MENU;
}

bool Login::pinValidation(const string &pinToCheck)
{
    if (pinToCheck.length() != 4)
    {
        cout << "Invalid PIN format, Please enter 4 digits only.\n";
        waitForUser();
        return false;
    }

    // check all digits
    for (char c : pinToCheck)
    {
        if (!isdigit(c))
        {
            cout << "Invalid PIN format, Please enter digits only.\n";
            waitForUser();
            return false;
        }
    }

    return true;
}