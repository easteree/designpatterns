#pragma once
#include "Meat.h"

namespace abstractfactorytoppings::meat
{

	class Ham : public Meat
	{
	public:
		std::string toString() override {return "Ham";}
	};

}
