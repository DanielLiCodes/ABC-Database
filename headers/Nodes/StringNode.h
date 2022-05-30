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
	// Creates a  database of string values
        void add(const string &context);
	// add a string value(data) into the data structure
        string get(const string &context) const;
	// given a key or value desired, this function will return the value at a desired location
        void set(const string &context);
	//it will ask for an id and data object to store, and then using a hash algorithm store the data in a position within the hash table given by the key.
        void remove(const string &context);
	// given an id, Using the hash algorithm, it will find the data stored at the location and delete it.
        string print();
	// it will print out the given data structure
        string getKey() const;
	// this function will return the key value to find a stored value in a data structure
        
};

#endif
