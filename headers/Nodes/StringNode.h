// FIX THIS! THIS IS ONLY TO COMPILE

#ifndef __String_DATABASE_NODE_H__
#define __String_DATABASE_NODE_H__

#include <vector>
#include "DatabaseNode.h"

using namespace std;
using namespace rapidjson;

class StringDatabaseNode : public DatabaseNode {
    private:
        string data;
    public:
        StringDatabaseNode(const string &key): DatabaseNode(key) {
            data = "";
        }
        void add(const string &context);
        string get(const string &context) const;
        void set(const string &context);
        void remove(const string &context);
        string print();
        string getKey() const;
        
};

#endif
