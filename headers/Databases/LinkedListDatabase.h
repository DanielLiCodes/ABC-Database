#ifndef __linkedlist_db__
#define __linkedlist_db__

#include "../Database.h"

class LinkedListDatabase : public Database {
private:
    struct LinkedListNode{
        LinkedListNode* next;
        unique_ptr<DatabaseNode>  data;
        LinkedListNode(unique_ptr<DatabaseNode>  data, LinkedListNode* next=nullptr): data(move(data)), next(next){}
    };
    LinkedListNode* head = nullptr;
    LinkedListNode* tail = nullptr;
public:
    ~LinkedListDatabase();
    LinkedListDatabase(const string &name) : Database(name) {}
    string at(int index);
    void add(const string &context);
    DatabaseNode*  get(const string &context);
    void set(const string &context);
    void remove(const string &context);
    int getSize();
    void sort(const string &name);

};

#endif
