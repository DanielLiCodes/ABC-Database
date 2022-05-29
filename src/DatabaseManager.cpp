#include "../headers/DatabaseManager.h"
#include "Databases/ArrayDatabase.cpp"
#include "Databases/HashTableDatabase.cpp"
#include "Databases/LinkedListDatabase.cpp"
#include "Nodes/JSONNode.cpp"
#include "Nodes/StringNode.cpp"
// #include "../headers/Databases/HashTableDatabase.h"
// #include "../headers/Databases/LinkedListDatabase.h"

// Adds default username and password
DatabaseManager::DatabaseManager()
{
    accessability.insert(pair<string, string>("admin", "admin"));
}

bool DatabaseManager::canAccess(const Credentials &acc)
{
    if (accessability.find(acc.user) != accessability.end())
    {
        if (accessability[acc.user] == acc.password)
        {
            return true;
        }
    }
    return false;
}

bool DatabaseManager::setAccess(const Credentials &acc, const Credentials &_new)
{
    if (this->canAccess(acc))
    {
        if (accessability.find(acc.user) != accessability.end())
        {
            accessability[acc.user] = _new.password;
            return true;
        }
        else
        {
            accessability.insert(pair<string, string>(_new.user, _new.password));
            return true;
        }
    }
    else
        return false;
}

Database* DatabaseManager::getDatabase(const string &name) const
{
    for (unsigned int i = 0; i < databases.size(); i++)
    {
        if (databases.at(i)->getName() == name)
        {
            return databases[i];
        }
    }
    return nullptr;
}

void DatabaseManager::createDatabase(const string &name, const string &type) {
    if (type == "array")
    {
        databases.push_back(new ArrayDatabase(name));
        cout << databases.size() << endl;
    }
}



vector<Database *> DatabaseManager::getDatabases() const
{
    return databases;
}

int DatabaseManager::size() const
{
    return databases.size();
}

// void DatabaseManager::addDatabase(Database *db)
// {
//     databases.push_back(db);
// }
