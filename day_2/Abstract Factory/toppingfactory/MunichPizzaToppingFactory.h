#pragma once

#include "toppings/dough/ThinCrustDough.h"
#include "toppings/meat/Weisswurst.h"
#include "PizzaToppingFactory.h"

namespace abstractfactorytoppingfactory
{

    class MunichPizzaToppingFactory : public PizzaToppingFactory
    {
        using ThinCrustDough = abstractfactorytoppings::dough::ThinCrustDough;
        using Weisswurst = abstractfactorytoppings::meat::Weisswurst;
    public:
        Dough* createDough() override
        {
            return new ThinCrustDough();
        }

        Sauce* createSauce() override
        {
            return nullptr;
        }

        Cheese* createCheese() override
        {
            return nullptr;
        }

        std::vector<Veggies*> createVeggies() override
        {
            return {};
        }

        Pepperoni* createPepperoni() override
        {
            return nullptr;
        }

        Clams* createClam() override
        {
            return nullptr;
        }

        Meat* createMeat() override
        {
            return new Weisswurst();
        }
    };

}
