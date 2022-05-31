#ifndef SORTING_STRATEGY
#define SORTING_STRATEGY
#include "../Nodes/DatabaseNode.h"

class SortingStrategy{
    public:
        virtual void sort(vector<unique_ptr<DatabaseNode> > &arr) = 0;
};

#endif
