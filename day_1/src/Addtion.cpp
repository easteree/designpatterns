#include <iostream>
#include "Addtion.hpp"


namespace design_pattern{

    void Addition::perform(int a, int b){
        std::cout << "Addition::perform(" << a << "," << b << ")=" << (a+b) << std::endl;
    }

}