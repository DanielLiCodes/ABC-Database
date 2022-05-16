#ifndef ARRAYDATABASE
#define ARRAYDATABASE
#include "SortingStrats/SortingStrategy"
#include <bits/stdc++.h>
using namespace std;

class ArrayDatabase : Database{
private:
    DatabaseNode* array[]
    int size;
public:
    string at(unsigned int index){
        if(index < 0 || index >= size) return "";
        return array[index];
    }
    
    unsigned int size(){
        return size;
    }
    
    void sort(string sortStrat="insertion"){
        SortingStrategy* strat = nullptr;
        if(toLower(sortStrat) == "bogo"){
            strat = new BogoSort(size);
        }else if(toLower(sortStrat) == "quick"){
            strat = new QuickSort(size);
        }else{
            strat = new InsertionSort(size);
        }
        strat->sort(array);
        delete strat;
    }
}
#endif
