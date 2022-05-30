#include "../../headers/Databases/HashTableDatabase.h"
#include "../../headers/Nodes/JSONNode.h"
#include "../../headers/Nodes/StringNode.h"

#include <string>
#include <sstream>
#include <numeric>
using namespace std;

//deconstructor for hashtable, go thru hashmap keys and delete all values
HashTableDatabase::~HashTableDatabase(){
    for(auto it = hashTable.begin(); it != hashTable.end(); it++){
        delete it->second;
    }
}


string HashTableDatabase::at(string key)
{
    int cur = 0;
    return hashTable[key]->print();
}

// example context add/str
void HashTableDatabase::add(const string &context)
{
    vector<string> ctx = getAllParameters(context);
    if (ctx.at(0) == "json")
    {
        JSONDatabaseNode *temp = new JSONDatabaseNode(ctx.at(1));
        temp->set(accumulate(next(ctx.begin(), 2), ctx.end(), std::string(""), addStrings).substr(1));
        hashTable[ctx.at(1)] = temp;
    }
    else if (ctx.at(0) == "string")
    {
        {
            StringDatabaseNode *temp = new StringDatabaseNode(ctx.at(1));
            temp->set(accumulate(next(ctx.begin(), 2), ctx.end(), std::string(""), addStrings).substr(1));
            hashTable[ctx.at(1)] = temp;
        }
    }
    else
    {
        throw "Proper node not defined";
    }
}
DatabaseNode *HashTableDatabase::get(const string &context)
{
    vector<string> ctx = getAllParameters(context);
    return hashTable[ctx.at(0)];
}
void HashTableDatabase::set(const string &context)
{
    vector<string> ctx = getAllParameters(context);
    hashTable[ctx.at(0)]->set(ctx.at(1));
}
void HashTableDatabase::remove(const string &context)
{
    vector<string> ctx = getAllParameters(context);
    hashTable.erase(ctx.at(0));
}
