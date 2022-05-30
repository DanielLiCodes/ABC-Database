#include "../../headers/Databases/ArrayDatabase.h"
#include "../../headers/SortingStrats/SortingStrategy.hpp"
#include "../../headers/SortingStrats/BogoSort.hpp"
#include "../../headers/SortingStrats/InsertionSort.hpp"
#include "../../headers/SortingStrats/SelectionSort.hpp"
#include "../../headers/Nodes/JSONNode.h"
#include "../../headers/Nodes/StringNode.h"

#include <string>
#include <sstream>
#include <numeric>
using namespace std;


ArrayDatabase::~ArrayDatabase(){
    for(int i = 0; i < arr.size(); i++){
        delete arr.at(i);
    }
}

void ArrayDatabase::sort(string sortStrat){
    SortingStrategy *temp = nullptr;
    if(sortStrat == "merge"){

    }else if(sortStrat == "quick"){

    }else{
        temp = new InsertionSort();
    }
    temp->sort(arr);
}


string ArrayDatabase::at(int index)
{
    return arr[index]->print();
}

// EXAMPLE CONTEXT: "json <key> <rest send to context of Node>"
// EXAMPLE CONTEXT: "string <key> <rest send to context of Node>"
void ArrayDatabase::add(const string &context)
{
    vector<string> ctx = getAllParameters(context);
    if (ctx.at(0) == "json")
    {
        JSONDatabaseNode *temp = new JSONDatabaseNode(ctx.at(1));
        temp->set(accumulate(next(ctx.begin(), 2), ctx.end(), std::string(""), addStrings).substr(1));
        arr.push_back(temp);
    }
    else if(ctx.at(0) == "string") {
        StringDatabaseNode *temp = new StringDatabaseNode(ctx.at(1));
        temp->set(accumulate(next(ctx.begin(), 2), ctx.end(), std::string(""), addStrings).substr(1));

        arr.push_back(temp);
    }
    else {
        throw "Proper node not defined";
    }
}

// EXAMPLE CONTEXT: "<key> <rest send to context of Node>"
DatabaseNode *ArrayDatabase::get(const string &context)
{
    vector<string> ctx = getAllParameters(context);
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr.at(i)->getKey() == ctx.at(0))
        {
            return arr.at(i);
        }
    }
    return nullptr;
}
void ArrayDatabase::set(const string &context)
{
    vector<string> ctx = getAllParameters(context);
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr.at(i)->getKey() == ctx.at(0))
        {
            arr.at(i)->set(ctx.at(1));
        }
    }
}

void ArrayDatabase::remove(const string &context)
{
    vector<string> ctx = getAllParameters(context);
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr.at(i)->getKey() == ctx.at(0))
        {
            arr.erase(arr.begin() + i);
        }
    }
}