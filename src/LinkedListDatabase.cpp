#include "../headers/Databases/LinkedListDatabase.h"
#include "Nodes/JSONNode.cpp"

#include <string>
#include <sstream>
using namespace std;


string LinkedListDatabase::at(int index){
    LinkedListNode* temp = head;
    int cur = 0;
    while(temp && cur < index){
        temp = temp->next;
        cur++;
    }
    return temp->data->print();
}

//example context add/str
void LinkedListDatabase::add(const string &context){
    istringstream ss(context);
    if(context.substr(0,4) == "json"){
        if(head == nullptr){
            JSONDatabaseNode* temp = new JSONDatabaseNode(context.substr(5));
            temp->set(context.substr(5));
            head = new LinkedListNode(temp);
            tail = head;
        }else{
            JSONDatabaseNode* temp = new JSONDatabaseNode(context.substr(5));
            temp->set(context.substr(5));
            tail->next = new LinkedListNode(temp);
            tail = tail->next;
        }
    }else{
        if(head == nullptr){
            StringDatabaseNode* temp = new StringDatabaseNode(context.substr(7));
            temp->set(context.substr(7));
            head = new LinkedListNode(temp);
            tail = head;
        }else{
            StringDatabaseNode* temp = new StringDatabaseNode(context.substr(7));
            temp->set(context.substr(7));
            tail->next = new LinkedListNode(temp);
            tail = tail->next;
        }
    }
}

DatabaseNode* LinkedListDatabase::get(const string &context){
    istringstream ss(context);
    if(context.substr(0,4) == "json"){
        LinkedListNode* temp2 = head;
        while(temp2){
            if(temp2->data->getKey() == context.substr(5)){
                return temp2->data;
            }
            temp2 = temp2->next;
        }
    }else{
        LinkedListNode* temp2 = head;
        while(temp2){
            if(temp2->data->getKey() == context.substr(7)){
                return temp2->data;
            }
            temp2 = temp2->next;
        }
    }
    return nullptr;
}    
void LinkedListDatabase::set(const string &context){
    int number = context.substr(0,4) == "json" ? 5 : 7;
    LinkedListNode* temp2 = head;
    while(temp2){
        if(temp2->data->getKey() == context.substr(number)){
            temp2->data->set(context.substr(number));
            temp2->data->setKey(context.substr(number));
            return;
        }
        temp2 = temp2->next;
    }
}
void LinkedListDatabase::remove(const string &context){
    istringstream ss(context);
    int number = 7;
    if(context.substr(0,4)=="json") number = 5;
    LinkedListNode* temp2 = head;
    if(head->data->getKey() == context.substr(number)){
        head = head->next;
        delete temp2;
        if(!head) tail = nullptr;
    }else{
        LinkedListNode* prev = temp2;
        temp2 = temp2->next;
        while(temp2){
            if(temp2->data->getKey() == context.substr(number)){
                prev->next = temp2->next;
                delete temp2;
                if (prev->next == nullptr){
                    tail = prev;
                }
                return;
            }
            temp2 = temp2->next;
            prev = prev->next;
        }
    }
}
