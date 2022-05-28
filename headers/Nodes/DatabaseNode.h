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
        virtual void add(const string &context) = 0;
        virtual string get(const string &context) const = 0;
        virtual void set(const string &context) = 0;
        virtual void remove(const string &context) = 0;
        virtual string print() = 0;
        virtual string getKey() const = 0;
        
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
};

#endif