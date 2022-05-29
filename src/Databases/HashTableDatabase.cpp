#include "../../headers/Databases/HashTableDatabase.h"
#include "../../headers/Nodes/JSONNode.h"
#include "../../headers/Nodes/StringNode.h"


#include <string>
#include <sstream>
using namespace std;


string HashTableDatabase::at(string key){
    int cur = 0;
    return hashTable[key]->print();
}

//example context add/str
void HashTableDatabase::add(const string &context){
    vector<string> ctx = getAllParameters(context);
    bool isJson = ctx.at(0) == "json";
    if(isJson){
        JSONDatabaseNode* temp = new JSONDatabaseNode(ctx.at(1));
        temp->set(ctx.at(2));
        hashTable[ctx.at(1)] = temp;
    }else{
        StringDatabaseNode* temp = new StringDatabaseNode(ctx.at(1));
        temp->set(ctx.at(2));
        hashTable[ctx.at(1)] = temp;
    }
}

DatabaseNode* HashTableDatabase::get(const string &context){
    vector<string> ctx = getAllParameters(context);
    return hashTable[ctx.at(0)];
}    
void HashTableDatabase::set(const string &context){
    vector<string> ctx = getAllParameters(context);
    hashTable[ctx.at(0)]->set(ctx.at(1));
}
void HashTableDatabase::remove(const string &context){
    vector<string> ctx = getAllParameters(context);
    hashTable.erase(ctx.at(0));
}
