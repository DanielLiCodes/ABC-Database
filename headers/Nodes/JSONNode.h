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
    public:
        JSONDatabaseNode(const string &key): DatabaseNode(key) {
            data.SetObject();
        }
        ~JSONDatabaseNode() {}
	// Creates a Json data structure of type defined by a key.
        void add(const string &context);
	// this will add data into the the datastructure
        string get(const string &context) const;
	// depednding on the data structure, it will use various methods to find the desired value and will return it
        void set(const string &context);
	//it will ask for an id and data object to store, and then using a hash algorithm store the data in a position within the hash table given by the key.
        void remove(const string &context);
	// given an id, Using the hash algorithm, it will find the data stored at the location and delete it.
        string print();
	// this function will print the data structure in its entirity
        string getKey() const;
	// function will return key value
        
};

#endif
