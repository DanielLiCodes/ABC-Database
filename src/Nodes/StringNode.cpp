#include "../../headers/Nodes/StringNode.h"

// EXAMPLE CONTEXT : "/john/age"
void StringDatabaseNode::add(const string &context) {
    vector<string> params = getAllParameters(context);
    Pointer(params.at(0).c_str()).Create(data);
}


// EXAMPLE CONTEXT : "/john/age 18"
void StringDatabaseNode::set(const string &context) {
    vector<string> params = getAllParameters(context);
    Pointer(params.at(0).c_str()).Set(data, params.at(1).c_str());
}


// EXAMPLE CONTEXT : "/john/age"
string StringDatabaseNode::get(const string &context) const {
    vector<string> params = getAllParameters(context);
    return Pointer(params.at(0).c_str()).Get(data)->GetString();
}


// EXAMPLE CONTEXT : "/john/age"
void StringDatabaseNode::remove(const string &context) {
    vector<string> params = getAllParameters(context);
    Pointer(params.at(0).c_str()).Erase(data);
}


string StringDatabaseNode::print() {
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    data.Accept(writer);
    return buffer.GetString();
}

string StringDatabaseNode::getKey() const {
    return key;
}