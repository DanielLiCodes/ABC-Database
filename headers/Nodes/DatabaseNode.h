#ifndef __DATABASE_NODE_H__
#define __DATABASE_NODE_H__

#include <map>
#include <string>

using namespace std;


class DatabaseNode {
    public:
        DatabaseNode(const string &key): key(key) {};
        ~DatabaseNode();
        virtual void add(const string &context) = 0;
        virtual string get(const string &context) const = 0;
        virtual void set(const string &context) = 0;
        virtual void remove(const string &context) = 0;
        virtual string print() = 0;
        
        // Splits the string based on spaces: "first second" -> ["first", "second"]
        vector<string> getAllParameters(string str) const {  
            vector<string> result;
            int pos = str.find(" ");
            while(pos != string::npos) {
                result.push_back(str.substr(0, pos));
                str = str.substr(pos + 1);
                pos = str.find(" ");
            }
            return result;
          }
    private:
        string key; 
};

#endif