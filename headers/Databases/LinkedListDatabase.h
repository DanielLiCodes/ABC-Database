#ifndef __linkedlist_db__
#define __linkedlist_db__

#include "../Database.h"

class LinkedListDatabase : public Database {
private:
    struct LinkedListNode{
        LinkedListNode* next;
        DatabaseNode* data;
        LinkedListNode(DatabaseNode* data, LinkedListNode* next=nullptr): data(data), next(next){}
    };
    LinkedListNode* head = nullptr;
    LinkedListNode* tail = nullptr;
public:
    ~LinkedListDatabase();
    string at(int index);
    void add(const string &context);
    DatabaseNode* get(const string &context);
    void set(const string &context);
    void remove(const string &context);

};

#endif