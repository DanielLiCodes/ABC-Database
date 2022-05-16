#ifndef __DATABASE_H__
#define __DATABASE_H__

#include <map>
#include <string>
#include "DatabaseNode.h"

using namespace std;

class Database
{
private:
    string name;
    int size;

public:
    Database();
    ~Database();
    virtual DatabaseNode add(const string &context) = 0;
    virtual DatabaseNode get(const string &context) = 0;
    virtual DatabaseNode set(const string &context) = 0;
    virtual DatabaseNode remove(const string &context) = 0;

    void sort();
    void print();
    string getName();
    int getSize();
};

#endif