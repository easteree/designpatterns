#ifndef POLICY
#define POLICY

#include "MergeSort.h"
#include "QuickSort.h"
#include "StdSort.h"
#include "Context.h"

namespace {
    MergeSort g_merge_sort{};
    QuickSort g_quick_sort{};
    StdSort g_std_sort{};
}


class Policy
{
    Context* m_context;

public:
    Policy(Context* context) : m_context{ context }
    {
        configure(true, true);
    }

    virtual void configure(bool timeIsImportant, bool spaceIsImportant)
    {
        if (timeIsImportant && !spaceIsImportant) {
            m_context->setSortAlgorithm(&g_merge_sort);
        }
        else if (timeIsImportant && spaceIsImportant) {
            m_context->setSortAlgorithm(&g_quick_sort);
        }
        else {
            m_context->setSortAlgorithm(&g_std_sort);
        }
    }
};


#endif	//#ifndef POLICY
