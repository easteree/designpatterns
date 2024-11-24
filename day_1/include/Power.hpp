#pragma once

#include "Operation.hpp"

namespace design_pattern{

    class Power : public Operation{
        public:
        /*\brief computes the power
        */
        void perform(int a, int to_thepower_of_b) override;
    };
}