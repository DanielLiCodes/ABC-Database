#ifndef __ARRAYDATABASE_H__
#define __ARRAYDATABASE_H__

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

    string at(int index);




};

#endif