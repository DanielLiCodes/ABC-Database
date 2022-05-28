#include "../../headers/Nodes/JSONNode.h"

// EXAMPLE CONTEXT : "add /john/age/18"
void JSONDatabaseNode::add(const string &context) {
    vector<string> params = getAllParameters(context);
    Pointer(params.at(1).c_str()).Create(data);
}


// EXAMPLE CONTEXT : "set /john/age 18"
void JSONDatabaseNode::set(const string &context) {
    vector<string> params = getAllParameters(context);
    Pointer(params.at(1).c_str()).Set(data, params.at(2).c_str());
}


// EXAMPLE CONTEXT : "get /john/age"
string JSONDatabaseNode::get(const string &context) const {
    vector<string> params = getAllParameters(context);
    return Pointer(params.at(1).c_str()).Get(data)->GetString();
}


// EXAMPLE CONTEXT : "delete /john/age"
void JSONDatabaseNode::remove(const string &context) {
    vector<string> params = getAllParameters(context);
    Pointer(params.at(1).c_str()).Erase(data);
}


string JSONDatabaseNode::print() {
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    data.Accept(writer);
    return buffer.GetString();
}