#ifndef CONFIG_DATABASE_DATABASE_HPP
#define CONFIG_DATABASE_DATABASE_HPP
#include "../sqlite/sqlite3.h"
#include <string>

using namespace std;

class Database
{
public:
    Database();
    ~Database();

    bool open(const string &dbName);
    void close();

    bool execute(const string &sql);

    sqlite3 *getDB();

private:
    sqlite3 *db;
};

#endif