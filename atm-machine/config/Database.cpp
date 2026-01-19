#include "Database.hpp"
#include <iostream>

using namespace std;

Database::Database()
{
    db = nullptr;
}

Database::~Database()
{
    close();
}

bool Database::open(const string &dbName)
{
    int result = sqlite3_open(dbName.c_str(), &db);

    if (result != SQLITE_OK)
    {
        cerr << "Database open failed: "
             << sqlite3_errmsg(db) << endl;
        return false;
    }

    cout << "Database opened successfully. \n";
    return true;
}

void Database::close()
{
    if (db != nullptr)
    {
        sqlite3_close(db);
        db = nullptr;
    }
}

bool Database::execute(const string &sql)
{
    char *errorMessage = nullptr;

    int result = sqlite3_exec(
        db,
        sql.c_str(),
        nullptr,
        nullptr,
        &errorMessage);

    if (result != SQLITE_OK)
    {
        cerr << "SQL Error: " << errorMessage << endl;
        sqlite3_free(errorMessage);
        return false;
    }

    return true;
}

sqlite3 *Database::getDB()
{
    return db;
}
