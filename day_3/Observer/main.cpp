#include <iostream>
#include "stockmanager_observer.hpp"
#include "stockmanger_withoutObserver.hpp"
#include "stockmanager_products_with_observer.hpp"
#include "streaming_platform/StreamingPlatform.hpp"

int main() {

    std::cout << std::endl << std::endl;
    std::cout << "################ stockmanager_observer #################" << std::endl;
    std::cout << std::endl;
    stockmanager_observer::main();

    std::cout << std::endl << std::endl;
    std::cout << "############# stockmanger_withoutObserver ##############" << std::endl;
    std::cout << std::endl;
    stockmanger_withoutObserver::main();


    std::cout << std::endl << std::endl;
    std::cout << "######### stockmanager_products_with_observer ##########" << std::endl;
    std::cout << std::endl;
    stockmanager_products_with_observer::main();

    std::cout << std::endl << std::endl;
    std::cout << "################## StreamingPlatform ###################" << std::endl;
    std::cout << std::endl;
    streaming_platform::main();
}
