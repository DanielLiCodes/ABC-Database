#ifndef __DATABASE_H__
#define __DATABASE_H__

#include <unordered_map>
#include <string>
#include "./Nodes/DatabaseNode.h"

using namespace std;

class Database
{
protected:
    string name;
    int size;
    unordered_map<string, string> accessability;
    bool canAccess(string username, string password){
        return (accessability.find(username) != accessability.end() && accessability[username] == password);
    }
    

public:
    Database(string username="admin", string password="admin"){
        accessability[username] = password;
    }
    bool setAccess(string username, string password, string newName, string newPass){
        if(accessability.find(username) != accessability.end() && accessability[username] == password){
            accessability[newName] = newPass;
            return true;
        }
        return false;
    }
    virtual void add(const string &context) = 0;
    virtual DatabaseNode* get(const string &context) = 0;
    virtual void set(const string &context) = 0;
    virtual void remove(const string &context) = 0;

    void sort();
    void print();
    string getName() {return name;};
    int getSize();
};

#endif