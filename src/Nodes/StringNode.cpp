#include "../../headers/Nodes/StringNode.h"

// EXAMPLE CONTEXT : "/john/age"
void StringDatabaseNode::add(const string &context) {
    string temp = context + " " + data;
    data = temp;
}


// EXAMPLE CONTEXT : "/john/age 18"
void StringDatabaseNode::set(const string &context) {
    data = context;
}


// EXAMPLE CONTEXT : "/john/age"
string StringDatabaseNode::get(const string &context) const {
    return data;
}


// EXAMPLE CONTEXT : "/john/age"
void StringDatabaseNode::remove(const string &context) {
    data = "";
}


string StringDatabaseNode::print() {
    return data;
}

string StringDatabaseNode::getKey() const {
    return key;
}