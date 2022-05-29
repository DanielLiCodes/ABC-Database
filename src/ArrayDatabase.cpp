#include "../headers/Databases/ArrayDatabase.h"
#include "../headers/SortingStrats/SortingStrategy.hpp"
#include "../headers/Nodes/JSONNode.h"
#include "../headers/Nodes/StringNode.h"

#include <string>
#include <sstream>
using namespace std;

// void ArrayDatabase::sort(string sortStrat="insertion"){
//     SortingStrategy* strat = nullptr;
//     if(sortStrat == "bogo"){
//         strat = new BogoSort(size);
//     }else if(sortStrat == "quick"){
//         strat = new QuickSort(size);
//     }else{
//         strat = new InsertionSort(size);
//     }
//     strat->sort(arr);
//     delete strat;
// }

string ArrayDatabase::at(int index){
    return arr[index]->print();
}

//EXAMPLE CONTEXT: "json <rest send to context of Node>"
//EXAMPLE CONTEXT: "string <rest send to context of Node>"
void ArrayDatabase::add(const string &context){
    istringstream ss(context);
    string type;
    ss >> type;
    bool isJson = type == "json";
    if(isJson){
        JSONDatabaseNode *temp = new JSONDatabaseNode(context.substr(5));
        temp->set(context.substr(5));
        arr.push_back(temp);
    }else{
        JSONDatabaseNode *temp = new StringDatabaseNode(context.substr(7));
        temp->set(context.substr(7));
        arr.push_back(temp);
    }
}
    // if(context.substr(0,4) == "json"){
    //     JSONDatabaseNode* temp = new JSONDatabaseNode(context.substr(5));
    //     temp->set(context.substr(5));
    //     arr.push_back(temp);
    // }
    // else{
    //     JSONDatabaseNode* temp = new StringDatabaseNode(context.substr(7));
    //     temp->set(context.substr(7));
    //     arr.push_back(temp);
    // }


//EXAMPLE CONTEXT: "get <rest send to context of Node>"
//EXAMPLE CONTEXT: "get <rest send to context of Node>"
DatabaseNode* ArrayDatabase::get(const string &context){
    if(context.substr(0,4) == "json"){
        for(int i = 0; i < arr.size(); i++){
            if(arr[i]->getKey() ==  context.substr(5)){
                return arr[i];
            }
        }
    }else{
        for(int i = 0; i < arr.size(); i++){
            if(arr[i]->getKey() ==  context.substr(7)){
                return arr[i];
            }
        }
    }
    return nullptr;
}    
void ArrayDatabase::set(const string &context){
    istringstream ss(context);
    string wordToLF;
    bool isJson = false;
    ss >> wordToLF;
    if(wordToLF == "json"){
        isJson = true;
    }
    for(int i = 0; i < arr.size(); i++){
        if(arr[i]->getKey() == wordToLF){
            if(isJson){
                arr[i]->set(context.substr(5));
                arr[i]->setKey(context.substr(5));
            }else{
                arr[i]->set(context.substr(7));
                arr[i]->setKey(context.substr(7));
            }
        }
    }
}

void ArrayDatabase::remove(const string &context){
    if(context.substr(0,4) == "json"){
        for(int i = 0; i < arr.size(); i++){
            if(arr[i]->getKey() ==  context.substr(5)){
                arr.erase(arr.begin()+i);
            }
        }
    }else{
        for(int i = 0; i < arr.size(); i++){
            if(arr[i]->getKey() == context.substr(7)){
                arr.erase(arr.begin()+i);
            }
        }
    }
}
// #ifndef ARRAYDATABASE
// #define ARRAYDATABASE
// #include "SortingStrats/SortingStrategy.hpp"
// #include <bits/stdc++.h>

// #include "../headers/Database.h"
// using namespace std;

// class ArrayDatabase : Database{
// private:
//     DatabaseNode *arr = nullptr;
//     int size;
// public:
//     string at(unsigned int index){
//         if(index < 0 || index >= size) return "";
//         return arr[index];
//     }
    
//     unsigned int size(){
//         return size;
//     }
    
//     void sort(string sortStrat="insertion"){
//         SortingStrategy* strat = nullptr;
//         if(toLower(sortStrat) == "bogo"){
//             strat = new BogoSort(size);
//         }else if(toLower(sortStrat) == "quick"){
//             strat = new QuickSort(size);
//         }else{
//             strat = new InsertionSort(size);
//         }
//         strat->sort(array);
//         delete strat;
//     }
// }
// #endif
