#ifndef PIZZA
#define PIZZA

#include "toppings/pepperoni/Pepperoni.h"
#include "toppings/sauce/Sauce.h"
#include "toppings/veggies/Veggies.h"
#include "toppings/cheese/Cheese.h"
#include "toppings/clams/Clams.h"
#include "toppings/dough/Dough.h"
#include "toppings/meat/Meat.h"
#include <string>
#include <vector>
#include <iostream>
#include "stringbuilder.h"

namespace abstractfactorypizza
{

	using Pepperoni = abstractfactorytoppings::pepperoni::Pepperoni;
	using Sauce = abstractfactorytoppings::sauce::Sauce;
	using Veggies = abstractfactorytoppings::veggies::Veggies;
	using Cheese = abstractfactorytoppings::cheese::Cheese;
	using Clams = abstractfactorytoppings::clams::Clams;
	using Dough = abstractfactorytoppings::dough::Dough;
	using Meat = abstractfactorytoppings::meat::Meat;

	class Pizza
	{
	public:
		std::string name;

		Dough* dough;
		Sauce* sauce;
		std::vector<Veggies*> veggies;
		Cheese* cheese;
		Pepperoni* pepperoni;
		Clams* clam;
		Meat* meat;

		virtual void prepare() = 0;

		virtual ~Pizza()
		{
			delete dough;
			delete sauce;
			delete cheese;
			delete pepperoni;
			delete clam;
			delete meat;
		}

		virtual void bake()
		{
			std::cout << "Bake for 25 minutes at 350" << std::endl;
		}

		virtual void cut()
		{
			std::cout << "Cutting the pizza into diagonal slices" << std::endl;
		}

		virtual void box()
		{
			std::cout << "Place pizza in official PizzaStore box" << std::endl;
		}

		virtual void setName(const std::string& name)
		{
			this->name = name;
		}

		virtual std::string getName()
		{
			return name;
		}

		virtual std::string toString()
		{
			StringBuilder* result = new StringBuilder();
			result->append("---- " + name + " ----\n");
			if (dough != nullptr)
			{
				result->append(dough);
				result->append("\n");
			}
			if (sauce != nullptr)
			{
				result->append(sauce);
				result->append("\n");
			}
			if (cheese != nullptr)
			{
				result->append(cheese);
				result->append("\n");
			}
			if (!veggies.empty())
			{
				for (int i = 0; i < veggies.size(); i++)
				{
					result->append(veggies[i]);
					if (i < veggies.size() - 1)
					{
						result->append(", ");
					}
				}
				result->append("\n");
			}
			if (clam != nullptr)
			{
				result->append(clam);
				result->append("\n");
			}
			if (pepperoni != nullptr)
			{
				result->append(pepperoni);
				result->append("\n");
			}
			if (meat != nullptr)
			{
				result->append(meat);
				result->append("\n");
			}

			return result->toString();
		}
	};

}


#endif	//#ifndef PIZZA
