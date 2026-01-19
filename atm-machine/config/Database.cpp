#include "Database.hpp"
#include <iostream>

using namespace std;

// set db to null as default
Database::Database()
{
    db = nullptr;
}

// use destructor to close db
Database::~Database()
{
    close();
}

// open db
bool Database::open(const string &dbName)
{
    int rc = sqlite3_open(dbName.c_str(), &db);
    if (rc != SQLITE_OK)
    {
        cout << "Cannot open DB: " << sqlite3_errmsg(db) << endl;
        return false;
    }

    // CREATE TABLE
    string createTable =
        "CREATE TABLE IF NOT EXISTS Account ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "username TEXT UNIQUE,"
        "pin TEXT,"
        "BalanceUSD REAL DEFAULT 0,"
        "BalanceKHR REAL DEFAULT 0);";

    char *errorMessage = nullptr;
    rc = sqlite3_exec(db, createTable.c_str(), nullptr, nullptr, &errorMessage);
    if (rc != SQLITE_OK)
    {
        cout << "Create table error: " << errorMessage << endl;
        sqlite3_free(errorMessage);
        return false;
    }

    return true;
}

// methord to close db
void Database::close()
{
    if (db != nullptr)
    {
        sqlite3_close(db);
        db = nullptr;
    }
}

// Execute for CRUD operation
bool Database::execute(const string &sql)
{
    char *errorMessage = nullptr;
    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errorMessage);

    if (rc != SQLITE_OK)
    {
        cout << "SQL error: " << errorMessage << endl;
        sqlite3_free(errorMessage);
        return false;
    }

    return true;
};

// get db
sqlite3 *Database::getDB()
{
    return db;
}
