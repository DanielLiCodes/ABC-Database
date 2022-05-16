#ifndef __DATABASE_MANAGER_H__
#define __DATABASE_MANAGER_H__

#include <map>
#include <string>
#include "Database.h"
using namespace std;

class DatabaseManager
{
private:
    map<string, string> accessability;
    map<string, Database> data;

public:
    bool canAccess(const string &user, const string &password);
    void setAccess(const string &user, const string &password);
    Database getDatabase(const string &name);
};

#endif
