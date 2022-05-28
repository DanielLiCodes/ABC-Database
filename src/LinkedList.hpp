fndef LINKEDLISTDATABASE
#define LINKEDLISTDATABASE
#include <bits/stdc++.h>
using namespace std;

class LInkedListDatabase : Database{
private:
    //DatabaseNode* linkedList;
    DatabaseNode* head;
    DatabaseNode* tail;
public:
    string at(unsigned int index){
        if(index < 0){
            return head;
        }
        else if(index >= size) {
            return tail;
        }
        else{
            DatabaseNode* loc = head;
            int  i = 0;
            while(loc->next != nullptr & i!= index){
                loc = loc->next;
                i++;
            }
            return loc;
        }
    }
    // void insert(DatabaseNode* input){

    // }
    void push_front(DatabaseNode* input){
    if(head == nullptr)
        head = tail = input;
    else{    
        temp->next = this->head;
        head = temp;
    }
    }
}
#endif
