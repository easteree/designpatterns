#include "pizza/Pizza.h"
#include "pizzastore/ChicagoPizzaStore.h"
#include "pizzastore/NYPizzaStore.h"
#include "pizzastore/PizzaStore.h"
#include "pizzastore/MunichPizzaStore.h"
#include <string>
#include <vector>
#include <iostream>

using Pizza = abstractfactorypizza::Pizza;
using ChicagoPizzaStore = abstractfactorypizzastore::ChicagoPizzaStore;
using NYPizzaStore = abstractfactorypizzastore::NYPizzaStore;
using PizzaStore = abstractfactorypizzastore::PizzaStore;
using MunichPizzaStore = abstractfactorypizzastore::MunichPizzaStore;

int main()
{
	PizzaStore* nyStore = new NYPizzaStore();
	PizzaStore* chicagoStore = new ChicagoPizzaStore();
	PizzaStore* munichStore = new MunichPizzaStore();

	Pizza* pizza = nyStore->orderPizza("cheese");
	if(pizza != nullptr)
		std::cout << "Ethan ordered a " << pizza->getName() << std::endl;

	pizza = chicagoStore->orderPizza("cheese");
	if(pizza != nullptr)
		std::cout << "Joel ordered a " << pizza->getName() << std::endl;

	pizza = nyStore->orderPizza("clam");
	if(pizza != nullptr)
		std::cout << "Ethan ordered a " << pizza->getName() << std::endl;

	pizza = chicagoStore->orderPizza("clam");
	if(pizza != nullptr)
		std::cout << "Joel ordered a " << pizza->getName() << std::endl;

	pizza = nyStore->orderPizza("pepperoni");
	if(pizza != nullptr)
		std::cout << "Ethan ordered a " << pizza->getName() << std::endl;

	pizza = chicagoStore->orderPizza("pepperoni");
	if(pizza != nullptr)
		std::cout << "Joel ordered a " << pizza->getName() << std::endl;

	pizza = nyStore->orderPizza("veggie");
	if(pizza != nullptr)
		std::cout << "Ethan ordered a " << pizza->getName() << std::endl;

	pizza = chicagoStore->orderPizza("veggie");
	if(pizza != nullptr)
		std::cout << "Joel ordered a " << pizza->getName() << std::endl;

	pizza = nyStore->orderPizza("meat");
	if(pizza != nullptr)
		std::cout << "Ethan ordered a " << pizza->getName() << std::endl;

	pizza = chicagoStore->orderPizza("meat");
	if(pizza != nullptr)
		std::cout << "Joel ordered a " << pizza->getName() << std::endl;

	pizza = munichStore->orderPizza("meat");
	if(pizza != nullptr)
		std::cout << "Edmund ordered a " << pizza->getName() << std::endl;


	if(chicagoStore != nullptr)
		delete chicagoStore;

	if(nyStore != nullptr)
		delete nyStore;

	if(munichStore != nullptr)
		delete munichStore;

}
