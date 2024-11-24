#include <iostream>
#include <cmath>
#include "Calculator.hpp"


namespace design_pattern{
    int Calculator::add(int a, int b){
        return a+b;
    }

    double Calculator::add(double a, double b){
        return a+b;
    }

    int Calculator::add(int a, int b, int c){
        return add(a,b)+c;
    }

}