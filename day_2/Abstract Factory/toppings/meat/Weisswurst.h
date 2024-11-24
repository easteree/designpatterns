#pragma once
#include "Meat.h"

namespace abstractfactorytoppings::meat
{

    class Weisswurst : public Meat
    {
    public:
        std::string toString() override { return "Weisswurst"; }
    };

}
