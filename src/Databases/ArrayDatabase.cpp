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
        arr.emplace_back(new JSONDatabaseNode(ctx.at(1)));
        arr.back()->set(accumulate(next(ctx.begin(), 2), ctx.end(), std::string(""), addStrings).substr(1));
    }
    else if(ctx.at(0) == "string") {
        arr.emplace_back(new StringDatabaseNode(ctx.at(1)));
        arr.back()->set(accumulate(next(ctx.begin(), 2), ctx.end(), std::string(""), addStrings).substr(1));
    }
    else {
        throw "Proper node not defined";
    }
}

void ArrayDatabase::sort(string sortStrat){
    SortingStrat* temp;
    if(sortStrat == "bogo"){
        temp = new bogoSort();
    }else if(sortStrat == "selection"){
        temp = new selectionSort();
    }else if(sortStrat == "quick"){
        temp = new quickSort();
    }else{
        temp = new insertionSort();
    }
    temp->sort(arr);
    delete temp;
}

// EXAMPLE CONTEXT: "<key> <rest send to context of Node>"
DatabaseNode* ArrayDatabase::get(const string &context)
{
    vector<string> ctx = getAllParameters(context);
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr.at(i)->getKey() == ctx.at(0))
        {
            return arr.at(i).get();
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
