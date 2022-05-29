#include "../../headers/Databases/HashTableDatabase.h"
#include "../../headers/Nodes/JSONNode.h"
#include "../../headers/Nodes/StringNode.h"


#include <string>
#include <sstream>
using namespace std;


string HashTableDatabase::at(string key){
    int cur = 0;
    return hashTable[key]->print();
}

//example context add/str
void HashTableDatabase::add(const string &context){
    istringstream ss(context);
    int idx = context.rfind('/');
    string name = context.substr(idx+1);
    string temp;
    ss >> temp >> temp >> temp;
    if(temp.substr(0,4) == "json"){
    }
}

DatabaseNode* HashTableDatabase::get(const string &context){
    istringstream ss(context);
    string temp;
    ss >> temp >> temp >> temp;
    if(temp.substr(0,4) == "json"){

    }
    return nullptr;
}    
void HashTableDatabase::set(const string &context){
    //??
}
void HashTableDatabase::remove(const string &context){
    istringstream ss(context);
    string temp;
    ss >> temp >> temp >> temp;
    if(temp.substr(0,4) == "json"){
        
    }
}
