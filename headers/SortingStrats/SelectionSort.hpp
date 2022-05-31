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
        void sort(vector<unique_ptr<DatabaseNode> > &arr){
            
            //find min in unsorted array
            for(int i = 0; i < arr.size(); i++){
                int smallest = i;
                for(int j = i+1; j < arr.size(); j++){
                    if(arr[j]->print() < arr[smallest]->print()){
                        smallest = j;
                    }
                }
                //swap min index with first index (i)
                unique_ptr<DatabaseNode>  temp = move(arr[i]);
                arr[i] = move(arr[smallest]);
                arr[smallest] = move(temp);
            }
        }
};

#endif
