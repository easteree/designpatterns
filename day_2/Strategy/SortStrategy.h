#ifndef SORTSTRATEGY
#define SORTSTRATEGY

#include <vector>

class SortStrategy
{
public:
    virtual void performSort(std::vector<int>& i_array) = 0;

    virtual ~SortStrategy() = default;
};

#endif	//#ifndef SORTSTRATEGY
