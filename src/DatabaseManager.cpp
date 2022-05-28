#include "../headers/DatabaseManager.h"
#include "../headers/Databases/ArrayDatabase.h"
#include "../headers/Databases/HashTableDatabase.h"
#include "../headers/Databases/LinkListDatabase.h"

// Adds default username and password
DatabaseManager::DatabaseManager() {
    accessability.insert(pair<string, string>("admin", "admin"));
}

bool DatabaseManager::canAccess(const Credentials &acc) {
    if (accessability.find(acc.user) != accessability.end()) {
        if (accessability[acc.user] == acc.password) {
            return true;
        }
    }
    return false;
}

bool DatabaseManager::setAccess(const Credentials &acc, const Credentials &_new) {
    if(this->canAccess(acc)) {
        if (accessability.find(acc.user) != accessability.end()) {
            accessability[acc.user] = _new.password;
            return true;
        }
        else {
            accessability.insert(pair<string, string>(_new.user, _new.password));
            return true;
        }
    }
    else return false;
    
}

Database* DatabaseManager::getDatabase(const string &name) const {
    for(unsigned int i = 0; i < databases.size(); i++) {
        if(databases.at(i)->getName() == name) {
            return databases[i];
        }
    }
}

void DatabaseManager::createDatabase(const string &name, const string &type) {
    if(type === "hash" || type === "hashtable") {
        Database* db = new HashTableDatabase(name, type);
        databases.push_back(db);
    }
    else if(type === "linked" || type === "linkedlist") {
        Database* db = new LinkedListDatabase(name, type);
        databases.push_back(db);
    }
    else if(type === "arr" || type === "array") {
        Database* db = new ArrayDatabase(name, type);
        databases.push_back(db);
    }
}