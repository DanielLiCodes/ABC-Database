#pragma once
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

public:
    Database(const string& name) : name(name) {}
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