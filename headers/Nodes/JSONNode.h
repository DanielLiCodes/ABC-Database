#ifndef __JSON_DATABASE_NODE_H__
#define __JSON_DATABASE_NODE_H__

#include <vector>
#include "DatabaseNode.h"


#include "rapidjson/document.h"
#include "rapidjson/pointer.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace std;
using namespace rapidjson;

class JSONDatabaseNode : public DatabaseNode {
    private:
        Document data;
        string key;
    public:
        // JSONDatabaseNode(const string &key) {
        //     this->key = key;
        //     data.SetObject();
        // }
        JSONDatabaseNode();
        void add(const string &context);
        string get(const string &context) const;
        void set(const string &context);
        void remove(const string &context);
        string print();
        string getKey() const;
        
};

#endif