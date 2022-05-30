#ifndef LINKEDLISTDATABASE_HPP
#define LINKEDLISTDATABASE_HPP
#include <bits/stdc++.h>
using namespace std;

class LinkedListDatabase : Database
{
private:
    DatabaseNode *head;
    DatabaseNode *tail;

public:
    LinkedlistDatabase() { head = nullptr; }
    string at(int);
    void insertHead(DatabaseNode**, int);
    void insertAfter(DatabaseNode**, int);
    void insertTail(DatabaseNode**, int);
    void deleteNode(DatabaseNode**, int);
    void push_front(DatabaseNode *);
}
#endif


