#ifndef QUICKSORT
#define QUICKSORT

#include "./SortingStrategy.hpp"
#include "../Nodes/DatabaseNode.h"
#include <vector>
using namespace std;
class QuickSort : public SortingStrategy{
    public:
        QuickSort(){}
        
    private:
    
        //find partition. sort elements before the partition and elements after
        void sort(vector<DatabaseNode*> &arr){
            quickSort(arr, 0, arr.size()-1);
        }

        void quickSort(vector<DatabaseNode*> &arr, int l, int h){
            if(l < h){
                int part_in = partition(arr, l, h);
                quickSort(arr, l, part_in-1);
                quickSort(arr, part_in+1, h);
            }
        }

        //place pivot index in the correct position in the array
        int partition(vector<DatabaseNode*> &arr, int low, int high){
            DatabaseNode* pivot = arr[low];
            int i = low+1;

            for(int j = low+1; j <= high; j++){
                if(arr[j]->print() < pivot->print()){
                    swap(arr, i, j);
                    i++;
                }
            }
            swap(arr, low, i-1);
            return(i - 1);
        }
        void swap(vector<DatabaseNode*> &arr, int a, int b){
            DatabaseNode* temp = arr[a];
            arr[a] = arr[b];
            arr[b] = temp;
        }
};

#endif
