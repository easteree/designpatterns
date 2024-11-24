#include <iostream>
#include <cmath>
#include "Power.hpp"


namespace design_pattern{

    void Power::perform(int a, int b){
        std::cout << "Power::perform(" << a << "," << b << ")=" << std::pow(a,b) << std::endl;
    }

}