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
            int h = arr.size();
            int l = 0;
            
            if(l < h){
                int part_in = partition(arr, l, h);

                sort(arr, l, part_in-1);
                sort(arr, part_in+1, h);
            }
        }
        //place pivot index in the correct position in the array
        int partition(vector<DatabaseNode*> &arr, int low, int high){
            DatabaseNode* pivot = arr[high];
            int i = (low - 1);

            for(int j = low; j <= high-1; j++){
                if(arr[j] < pivot){
                    i++;
                    swap(arr, i, j);
                }
            }
            swap(arr, i + 1, high);
            return(i + 1);
        }
        void swap(vector<DatabaseNode*> &arr, int a, int b){
            DatabaseNode* temp = arr[a];
            arr[a] = arr[b];
            arr[b] = temp;
        }
};

#endif
