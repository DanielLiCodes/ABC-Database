#ifndef SELECTION
#define SELECTION

#include "./SortingStrategy.hpp"
#include "../Nodes/DatabaseNode.h"
#include <vector>
using namespace std;


class SelectionSort : public SortingStrategy{
    public:
        SelectionSort(){}
    private:
        void sort(vector<DatabaseNode*> &arr){
            
            //find min in unsorted array
            for(int i = 0; i < arr.size(); i++){
                int smallest = i;
                for(int j = i+1; j < arr.size(); j++){
                    if(arr[j]->print() < arr[smallest]->print()){
                        smallest = j;
                    }
                }
                //swap min index with first index (i)
                DatabaseNode* temp = arr[i];
                arr[i] = arr[smallest];
                arr[smallest] = temp;
            }
        }
};

#endif
