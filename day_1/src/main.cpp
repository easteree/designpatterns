#include <iostream>
#include "Calculator.hpp"
#include "Addtion.hpp"
#include "Power.hpp"
#include "Stack.hpp"
#include "GPS.hpp"

void exercise_overload(){
   design_pattern::Calculator calculator{};

   std::cout << "add(1,2)=" << calculator.add(1,2) << std::endl;
   std::cout << "add(1.0,2.0)=" << calculator.add(1.0,2.0) << std::endl;
   std::cout << "add(1,2,3)=" << calculator.add(1,2,3) << std::endl;
}

void exercise_override(){
   design_pattern::Addition addition{};
   addition.perform(1,2);

   design_pattern::Power power{};
   power.perform(2,3);
}


void exercise_stack() {
    design_pattern::delegate::Stack stack_delegate{};
    design_pattern::derived::Stack stack_derived{};

    for (auto& v : std::list{ 1.,2.,3. }) {
        stack_delegate.push(v);
        stack_derived.push(v);
    }

    std::cout << "delegate::Stack" << std::endl;
    while (stack_delegate.size()) {
        std::cout << stack_delegate.pop() << std::endl;
    }


    std::cout << "derived::Stack" << std::endl;
    while (stack_derived.size()) {
        std::cout << stack_derived.pop() << std::endl;
    }
}

void exercise_static_creator() {

    using GPS = design_pattern::GPS;

    for (const auto& str : std::list<std::string>{ "49,48","-2aw3.2,45.2","-23.2 45.2", "-23.2,-45.2" }) {
        try {
            auto gps=GPS::fromLine(str);
            std::cout << gps << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

}

int main(){
    //exercise_overload();
    //exercise_override();
    //exercise_stack();
    exercise_static_creator();
    return 0;
}
