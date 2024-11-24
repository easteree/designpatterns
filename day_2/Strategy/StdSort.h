#ifndef STDSORT
#define STDSORT

#include <algorithm>
#include "SortStrategy.h"

/***********************************************************************
 * Sort the array a using mergesort
 ***********************************************************************/
class StdSort : public SortStrategy
{

public:

    void performSort(std::vector<int>& i_array) override {
        std::sort(std::begin(i_array), std::end(i_array));
    }

};


#endif	//#ifndef MERGESORT
