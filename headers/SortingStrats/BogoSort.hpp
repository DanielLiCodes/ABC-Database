#ifndef BOGOSORT
#define BOGOSORT

#include "./SortingStrategy.hpp"
#include <stdlib.h>
#include "../Nodes/DatabaseNode.h"
#include <vector>
using namespace std;

class BogoSort : public SortingStrategy{
    public:
        BogoSort(unsigned int size){}
    private:
        void randomShuffle(vector<DatabaseNode*> arr){
            for(int i = 0; i < arr.size(); i++){
                int randd = rand() % arr.size();
                DatabaseNode* temp = arr[i];
                arr[i] = arr[randd];
                arr[randd] = temp;
            }
        }

        bool inOrder(vector<DatabaseNode*> &arr){
            for(int i = 1; i < arr.size(); i++){
                if(arr[i]->print() < arr[i-1]->print()){
                    return false;
                }
            }
            return true;
        }

        void sort(vector<DatabaseNode*> &arr){
            while(!inOrder(arr)){
                randomShuffle(arr);
            }
        }
};

#endif
