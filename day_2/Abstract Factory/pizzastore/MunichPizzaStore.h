#pragma once

#include "pizza/MeatPizza.h"
#include "toppingfactory/MunichPizzaToppingFactory.h"
#include "toppingfactory/PizzaToppingFactory.h"
#include "PizzaStore.h"

namespace abstractfactorypizzastore
{
    class MunichPizzaStore : public PizzaStore
    {
        using Pizza = abstractfactorypizza::Pizza;
        using MeatPizza = abstractfactorypizza::MeatPizza;
        using MunichPizzaToppingFactory = abstractfactorytoppingfactory::MunichPizzaToppingFactory;
        using PizzaToppingFactory = abstractfactorytoppingfactory::PizzaToppingFactory;

        Pizza* pizza;
        PizzaToppingFactory* ingredientFactory;
    public:
        ~MunichPizzaStore()
        {
            if (pizza != nullptr)
                delete pizza;
            if (ingredientFactory != nullptr)
                delete ingredientFactory;
        }

    protected:
        Pizza* createPizza(const std::string& item) override
        {
            pizza = nullptr;
            ingredientFactory = new MunichPizzaToppingFactory();

            if (item == "meat")
            {

                pizza = new MeatPizza(ingredientFactory);
                pizza->setName("Munich Style Meat Pizza");

            }

            return pizza;
        }
    };

}
