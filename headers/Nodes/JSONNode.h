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
        JSONDatabaseNode(const string &key) {
            this->key = key;
            data.SetObject();
        }
        JSONDatabaseNode();
        void add(const string &context);
        string get(const string &context) const;
        void set(const string &context);
        void remove(const string &context);
        string print();
        string getKey() const;
        
};

#endif


// EXAMPLE CONTEXT : "/john/age"
void JSONDatabaseNode::add(const string &context) {
    vector<string> params = getAllParameters(context);
    Pointer(params.at(0).c_str()).Create(data);
}


// EXAMPLE CONTEXT : "/john/age 18"
void JSONDatabaseNode::set(const string &context) {
    vector<string> params = getAllParameters(context);
    Pointer(params.at(0).c_str()).Set(data, params.at(1).c_str());
}


// EXAMPLE CONTEXT : "/john/age"
string JSONDatabaseNode::get(const string &context) const {
    vector<string> params = getAllParameters(context);
    return Pointer(params.at(0).c_str()).Get(data)->GetString();
}


// EXAMPLE CONTEXT : "/john/age"
void JSONDatabaseNode::remove(const string &context) {
    vector<string> params = getAllParameters(context);
    Pointer(params.at(0).c_str()).Erase(data);
}


string JSONDatabaseNode::print() {
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    data.Accept(writer);
    return buffer.GetString();
}

string JSONDatabaseNode::getKey() const {
    return key;
}