#pragma once
#ifndef __ARRAYDATABASE_H__
#define __ARRAYDATABASE_H__

#include "../SortingStrats/SortingStrategy.hpp"
#include "../Database.h"
#include <vector>
using namespace std;

class ArrayDatabase : public Database
{
private:
    vector<DatabaseNode *> arr;
public:
    ArrayDatabase(const string &name) : Database(name) {}
    ~ArrayDatabase();
    void sort(string sortStrat = "insertion");
    string at(int index);
    void add(const string &context);
    DatabaseNode *get(const string &context);
    void set(const string &context);
    void remove(const string &context);
    int getSize() { return arr.size();};
};

#endif
