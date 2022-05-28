#ifndef __DATABASE_MANAGER_H__
#define __DATABASE_MANAGER_H__

#include <map>
#include <string>
#include <vector>
#include "Database.h"

using namespace std;


struct Credentials {
    string user;
    string password;
};

class DatabaseManager
{
private:
    map<string, string> accessability;
    vector<Database*> databases;

public:
    DatabaseManager();
    bool canAccess(const Credentials &acc);
    bool setAccess(const Credentials &acc, const Credentials &_new);
    Database* getDatabase(const string &name) const;
    void createDatabase(const string &name, const string &type);
};

#endif
