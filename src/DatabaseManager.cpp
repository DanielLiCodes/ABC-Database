#include "../headers/DatabaseManager.h"
#include "Databases/ArrayDatabase.cpp"
#include "Databases/HashTableDatabase.cpp"
#include "Databases/LinkedListDatabase.cpp"
#include "Nodes/JSONNode.cpp"
#include "Nodes/StringNode.cpp"
// #include "../headers/Databases/HashTableDatabase.h"
// #include "../headers/Databases/LinkedListDatabase.h"

// Adds default username and password
DatabaseManager::DatabaseManager(vector<Database*>* databases)
{
    this->databases = databases;
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
    for (unsigned int i = 0; i < databases->size(); i++)
    {
        if (databases->at(i)->getName() == name)
        {
            return databases->at(i);
        }
    }
}

Database* DatabaseManager::createDatabase(const string &name, const string &type) {
    if (type == "array")
    {
        Database* database = new ArrayDatabase(name);
        cout << &database << endl;
        return database;
    }
}



vector<Database *>* DatabaseManager::getDatabases() const
{
    return databases;
}

string DatabaseManager::printDatabases() const
{
    stringstream ss;
    for (unsigned int i = 0; i < databases->size(); i++)
    {
        ss << databases->at(i)->getName() << " ";
    }
    return ss.str();
}


int DatabaseManager::size() const
{
    return databases->size();
}