#pragma once

namespace design_pattern{

    class Operation {
        public:
            virtual void perform(int a, int b)=0;
            virtual ~Operation() = default;
    };

}