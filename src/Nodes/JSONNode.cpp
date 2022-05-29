#include "../../headers/Nodes/JSONNode.h"

// EXAMPLE CONTEXT : "/john/age"
void JSONDatabaseNode::add(const string &context) {
    vector<string> params = getAllParameters(context);
    Pointer(params.at(0).c_str()).Create(data);
}


// EXAMPLE CONTEXT : "{\"john\":{\"jogn\":\"18\"}}"
void JSONDatabaseNode::set(const string &context) {
    data.Parse<0>(context.c_str());
}


// EXAMPLE CONTEXT : "/john/age" or ""
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