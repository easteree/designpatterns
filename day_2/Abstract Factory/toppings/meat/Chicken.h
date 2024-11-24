#pragma once
#include "Meat.h"

namespace abstractfactorytoppings::meat
{

	class Chicken : public Meat
	{
	public:
		std::string toString() override {return "Chicken";}
	};

}
