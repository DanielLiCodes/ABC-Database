#ifndef __DATABASE_NODE_H__
#define __DATABASE_NODE_H__

#include <map>
#include <string>

using namespace std;


class DatabaseNode {
    protected:
        string key;
    public:
        DatabaseNode(const string &key): key(key){}
	// creates a DatabaseNode and uses the key input to decide what type
        virtual void add(const string &context) = 0;
	// adds a value into a position 
        virtual string get(const string &context) const = 0;
	// given a key the get function will retrive the data stored at the desired location
        virtual void set(const string &context) = 0;
	// it will ask for an id and data object to store, and then using a hash algorithm store the data in a position within the hash table given by the key.
        virtual void remove(const string &context) = 0;
	//given an id, Using the hash algorithm, it will find the data stored at the location and delete it
        virtual string print() = 0;
	//this function will print the data base out
        virtual string getKey() const = 0;
	//it will retirive the hash table key value required tp retrieve data values
        void setKey(string key){
            this->key = key;
        }
        
        // Splits the string based on spaces: "first second" -> ["first", "second"]
        vector<string> getAllParameters(const string& str) const {  
            vector<string> result;
            string copy = str;
            size_t pos = copy.find(" ");
            while(pos != string::npos) {
                result.push_back(copy.substr(0, pos));
                copy = copy.substr(pos + 1);
                pos = copy.find(" ");
            }
            result.push_back(copy.substr(pos + 1));
            return result;
          }
	//This function will get all given parameters of a database and return them as a vector
};

#endif
