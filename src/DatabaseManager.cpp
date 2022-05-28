#include "../headers/DatabaseManager.h"

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

// Database DatabaseManager::getDatabase(const string &name) const {
//     for(unsigned int i = 0; i < databases.size(); i++) {
//         if(databases.at(i).getName() == name) {
//             return databases.at(i);
//         }
//     }
// }

// Database DatabaseManager::createDatabase(const string &name, const string &type) {
//     Database newDatabase(name, type);
//     databases.push_back(newDatabase);
//     return newDatabase;
// }