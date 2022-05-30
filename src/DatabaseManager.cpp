#include "../headers/DatabaseManager.h"
#include "Databases/ArrayDatabase.cpp"
#include "Databases/HashTableDatabase.cpp"
#include "Databases/LinkedListDatabase.cpp"
#include "Nodes/JSONNode.cpp"
#include "Nodes/StringNode.cpp"


// Adds default username and password
DatabaseManager::DatabaseManager()
{
    accessability.insert(pair<string, string>("admin", "admin"));
}

DatabaseManager::~DatabaseManager()
{
    for (auto p : databases)
    {
        delete p;
    }
    databases.clear();
}

//check if the user's username and password match to allow/deny access
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

//set new password/credentials
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

//return database
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

//create new database based on type: array, hashtable, linkedlist
void DatabaseManager::createDatabase(const string &name, const string &type)
{
    if (type == "array")
    {
        databases.push_back(new ArrayDatabase(name));
    }
    else if (type == "hashtable")
    {
        databases.push_back(new HashTableDatabase(name));
    }
    else if (type == "linkedlist")
    {
        databases.push_back(new LinkedListDatabase(name));
    }
    else {
        throw "Invalid database type";
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


//remove database
void DatabaseManager::removeDatabase(const string &name)
{
    for (unsigned int i = 0; i < databases.size(); i++)
    {
        if (databases.at(i)->getName() == name)
        {
            delete databases[i];
            databases.erase(databases.begin() + i);
        }
    }
}


