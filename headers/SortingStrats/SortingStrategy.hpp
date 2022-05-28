#ifndef SORTING_STRATEGY
#define SORTING_STRATEGY

class SortingStrategy{
    protected:
        unsigned int size;

        virtual void sort() = 0;
};

#endif
