#include "../../headers/Databases/HashTableDatabase.h"
#include "../../headers/Nodes/JSONNode.h"
#include "../../headers/Nodes/StringNode.h"

#include <string>
#include <sstream>
#include <numeric>
using namespace std;

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
        hashTable[ctx.at(1)] = unique_ptr<DatabaseNode> (new JSONDatabaseNode(ctx.at(1)));
        hashTable[ctx.at(1)]->set(accumulate(next(ctx.begin(), 2), ctx.end(), std::string(""), addStrings).substr(1));
    }
    else if (ctx.at(0) == "string")
    {
        hashTable[ctx.at(1)] = unique_ptr<DatabaseNode> (new StringDatabaseNode(ctx.at(1)));
        hashTable[ctx.at(1)]->set(accumulate(next(ctx.begin(), 2), ctx.end(), std::string(""), addStrings).substr(1));
    }
    else
    {
        throw "Proper node not defined";
    }
}
DatabaseNode* HashTableDatabase::get(const string &context)
{
    vector<string> ctx = getAllParameters(context);
    return hashTable[ctx.at(0)].get();
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
