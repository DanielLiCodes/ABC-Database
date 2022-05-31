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
    Database(const string &name) : name(name) {}
    virtual ~Database() {};
    virtual void add(const string &context) = 0;
    virtual DatabaseNode* get(const string &context) = 0;
    virtual void set(const string &context) = 0;
    virtual void remove(const string &context) = 0;

    void sort();
    string print();
    string getName() { return name; };
    
    //put all parameters in a vector of strings
    vector<string> getAllParameters(const string &str) const
    {
        vector<string> result;
        string copy = str;
        size_t pos = copy.find(" ");
        //if not a space, then put the parameter in the vector
        while (pos != string::npos)
        {
            //store the string until next space is found
            result.push_back(copy.substr(0, pos));
            copy = copy.substr(pos + 1);
            pos = copy.find(" ");
        }
        result.push_back(copy.substr(pos + 1));
        return result;
    }
    static string addStrings (string x, string y) {return x + " " + y;};
    virtual int getSize() = 0;
};

#endif
