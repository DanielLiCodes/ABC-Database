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
    int idx = context.rfind('/');
    string name = context.substr(idx+1);
    string temp;
    ss >> temp >> temp >> temp;
    if(temp.substr(0,4) == "json"){
        if(head == nullptr){
            head = new LinkedListNode(new JSONDatabaseNode(temp.substr(6,temp.length()-6)));
            tail = head;
        }else{
            tail->next = new LinkedListNode(new JSONDatabaseNode(temp.substr(6,temp.length()-6)));
            tail = tail->next;
        }
    }
}

DatabaseNode* LinkedListDatabase::get(const string &context){
    istringstream ss(context);
    string temp;
    ss >> temp >> temp >> temp;
    if(temp.substr(0,4) == "json"){
        LinkedListNode* temp2 = head;
        while(temp2){
            if(temp2->data->print() ==  temp.substr(6,temp.length()-6)){
                return temp2->data;
            }
            temp2 = temp2->next;
        }
    }
    return nullptr;
}    
void LinkedListDatabase::set(const string &context){
    //??
}
void LinkedListDatabase::remove(const string &context){
    istringstream ss(context);
    string temp;
    ss >> temp >> temp >> temp;
    if(temp.substr(0,4) == "json"){
        LinkedListNode* temp2 = head;
        if(head->data->print() == temp.substr(6, temp.length()-6)){
            head = head->next;
            delete temp2;
            if(!head) tail = nullptr;
        }else{
            temp2 = temp2->next;
            while(temp2){
                if(temp2->data->print() == temp.substr(6, temp.length()-6)){
                    LinkedListNode* temp3 = temp2->next;
                    temp2->next = temp3 ? temp3->next : nullptr;
                    delete temp3;
                    if(!temp2->next) tail = temp2;
                    break;
                }else{
                    temp2 = temp2->next;
                }
            }
        }
    }
}
