#include "../../headers/Databases/LinkedListDatabase.h"
#include "../../headers/Nodes/JSONNode.h"
#include "../../headers/Nodes/StringNode.h"


#include <string>
#include <sstream>
#include <numeric>
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
    vector<string> ctx = getAllParameters(context);
    if(ctx.at(0) == "json") {
        if(head == nullptr){
            JSONDatabaseNode* temp = new JSONDatabaseNode(ctx.at(1));
            temp->set(accumulate(next(ctx.begin(), 2), ctx.end(), std::string(""), addStrings).substr(1));
            head = new LinkedListNode(temp);
            tail = head;
        } else{
            JSONDatabaseNode* temp = new JSONDatabaseNode(ctx.at(1));
            temp->set(accumulate(next(ctx.begin(), 2), ctx.end(), std::string(""), addStrings).substr(1));
            tail->next = new LinkedListNode(temp);
            tail = tail->next;
        }
    }
    else if(ctx.at(0) == "string") {
        if(head == nullptr){
            StringDatabaseNode* temp = new StringDatabaseNode(ctx.at(1));
            temp->set(accumulate(next(ctx.begin(), 2), ctx.end(), std::string(""), addStrings).substr(1));
            head = new LinkedListNode(temp);
            tail = head;
        } else{
            StringDatabaseNode* temp = new StringDatabaseNode(ctx.at(1));
            temp->set(accumulate(next(ctx.begin(), 2), ctx.end(), std::string(""), addStrings).substr(1));
            tail->next = new LinkedListNode(temp);
            tail = tail->next;
        }
    }
    else {
        throw "Proper node not defined";
    }
}

DatabaseNode* LinkedListDatabase::get(const string &context){
    istringstream ss(context);
    vector<string> ctx = getAllParameters(context);
    LinkedListNode* temp = head;
    while(temp != nullptr) {
        if(temp->data->getKey() == ctx.at(0)){
            return temp->data;
        }
        temp = temp->next;
    }
    return nullptr;
}    
void LinkedListDatabase::set(const string &context){
    LinkedListNode* temp2 = head;
    vector<string> ctx = getAllParameters(context);
    while(temp2){
        if(temp2->data->getKey() == ctx.at(0)){
            temp2->data->set(ctx.at(1));
            return;
        }
        temp2 = temp2->next;
    }
}
void LinkedListDatabase::remove(const string &context){
    istringstream ss(context);
    vector<string> ctx = getAllParameters(context);
    LinkedListNode* temp2 = head;
    if(head->data->getKey() == ctx.at(0)){
        head = head->next;
        delete temp2;
        if(!head) tail = nullptr;
    }else{
        LinkedListNode* prev = temp2;
        temp2 = temp2->next;
        while(temp2){
            if(temp2->data->getKey() == ctx.at(0)){
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
