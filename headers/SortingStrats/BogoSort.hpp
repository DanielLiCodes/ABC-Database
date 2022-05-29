#ifndef BOGOSORT
#define BOGOSORT

#include "./SortingStrategy.hpp"
#include <stdlib.h>
#include "../Nodes/DatabaseNode.h"
#include <vector>
using namespace std;

class BogoSort : public SortingStrategy{
    public:
        BogoSort(){}
    private:
        //shuffle array indexes
        void randomShuffle(vector<DatabaseNode*> arr){
            for(int i = 0; i < arr.size(); i++){
                //randomly generate array index
                int randd = rand() % arr.size();
                DatabaseNode* temp = arr[i];
                //swap current index with the randd
                arr[i] = arr[randd];
                arr[randd] = temp;
            }
        }
        
        //check if nodes are in order
        bool inOrder(vector<DatabaseNode*> &arr){
            for(int i = 1; i < arr.size(); i++){
                if(arr[i]->print() < arr[i-1]->print()){
                    return false;
                }
            }
            return true;
        }
        
        //sort until in order
        void sort(vector<DatabaseNode*> &arr){
            while(!inOrder(arr)){
                randomShuffle(arr);
            }
        }
};

#endif
