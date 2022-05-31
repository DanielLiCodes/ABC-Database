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
        void sort(vector<unique_ptr<DatabaseNode> > &arr){
            for(int i = 1; i < arr.size(); i++){
                unique_ptr<DatabaseNode>  cur = move(arr[i]);
                int prev = i-1;
                //move indexes that are smaller one position behind
                while(cur->print() < arr[prev]->print() && prev >= 0){
                    arr[prev+1] = move(arr[prev]);
                    prev--;
                }
                arr[prev+1] = move(cur);
            }
        }
};

#endif
