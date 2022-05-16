#ifndef __DATABASE_NODE_H__
#define __DATABASE_NODE_H__

#include <map>
#include <string>
using namespace std;


class DatabaseNode {
public:
    DatabaseNode();
    ~DatabaseNode();
    virtual void add(const string &context) = 0;
    virtual void get(const string &context) = 0;
    virtual void set(const string &context) = 0;
    virtual void remove(const string &context) = 0;
    virtual void sort() = 0;
    virtual void print() = 0;
};

#endif