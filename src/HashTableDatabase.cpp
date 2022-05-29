#include "../headers/Databases/HashTableDatabase.h"
#include "Nodes/JSONNode.cpp"

#include <string>
#include <sstream>
using namespace std;


string HashTableDatabase::at(string key){
    int cur = 0;
    return hashTable[key]->print();
}

//example context add/str
void HashTableDatabase::add(const string &context){
    istringstream ss(context);
    string key;
    ss >> key >> key;
    bool isJson = context.substr(0,4) == "json";
    if(isJson){
        JSONDatabaseNode* temp = new JSONDatabaseNode(key);
        temp->set(context.substr(5+key.length()+1));
        hashTable[key] = temp;
    }else{
        StringDatabaseNode* temp = new StringDatabaseNode(key);
        temp->set(context.substr(7+key.length()+1));
        hashTable[key] = temp;
    }
}

DatabaseNode* HashTableDatabase::get(const string &context){
    istringstream ss(context);
    string key;
    ss >> key >> key;
    return hashTable[key];
}    
void HashTableDatabase::set(const string &context){
    istringstream ss(context);
    string key;
    ss >> key >> key;
    hashTable[key]->set(context.substr(5+key.length()+1));
}
void HashTableDatabase::remove(const string &context){
    istringstream ss(context);
    string key;
    ss >> key >> key;
    hashTable.erase(key);
}
