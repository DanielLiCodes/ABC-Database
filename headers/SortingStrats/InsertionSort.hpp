#ifndef INSERTIONSORT
#define INSERTIONSORT

#include "./SortingStrategy.hpp"
#include "../Nodes/DatabaseNode.h"
#include <vector>
using namespace std;


class InsertionSort : public SortingStrategy{
    public:
        InsertionSort(){}
    private:
        void sort(vector<DatabaseNode*> &arr){
            for(int i = 0; i < arr.size(); i++){
                int smallest = i;
                for(int j = i+1; j < arr.size(); j++){
                    if(arr[j]->print() < arr[smallest]->print()){
                        smallest = j;
                    }
                }
                DatabaseNode* temp = arr[i];
                arr[i] = arr[smallest];
                arr[smallest] = temp;
            }
        }
};

#endif
