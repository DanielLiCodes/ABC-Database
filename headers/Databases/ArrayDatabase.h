#ifndef __ARRAYDATABASE_H__
#define __ARRAYDATABASE_H__

#include "../SortingStrats/SortingStrategy.hpp"
#include "../Database.h"
#include <vector>
using namespace std;

class ArrayDatabase : public Database {
private:
    vector<DatabaseNode*> arr;
    int size;
    int capacity = 10;
public:
    ArrayDatabase(string username="admin", string pw = "admin") : Database(username, pw) {}

    void sort(string SortingStrategy="insertion");
    string at(int index);
    void add(const string &context);
    DatabaseNode* get(const string &context);
    void set(const string &context);
    void remove(const string &context);

    // DatabaseNode* add(const string &context){
    //     DatabaseNode* temp = new stringNode(context);
    //     arr.push_back(temp);
    //     return temp;
    // }
};

#endif