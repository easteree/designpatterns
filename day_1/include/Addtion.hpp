#pragma once

#include "Operation.hpp"

namespace design_pattern{

    class Addition : public Operation{
        public:
        /*\brief computes the sum
        */
        void perform(int a, int b) override;
    };

}