cmake_minimum_required(VERSION 3.20)

project("Abstract Factory")

set(INCLUDE_FILES
  stringbuilder.h
  pizza/CheesePizza.h
  pizza/ClamPizza.h
  pizza/MeatPizza.h
  pizza/PepperoniPizza.h
  pizza/Pizza.h
  pizza/VeggiePizza.h
  pizzastore/ChicagoPizzaStore.h
  pizzastore/MunichPizzaStore.h
  pizzastore/NYPizzaStore.h
  pizzastore/PizzaStore.h
  toppingfactory/ChicagoPizzaToppingFactory.h
  toppingfactory/MunichPizzaToppingFactory.h
  toppingfactory/NYPizzaToppingFactory.h
  toppingfactory/PizzaToppingFactory.h
  toppings/cheese/Cheese.h
  toppings/cheese/MozzarellaCheese.h
  toppings/cheese/ParmesanCheese.h
  toppings/cheese/ReggianoCheese.h
  toppings/clams/Clams.h
  toppings/clams/FreshClams.h
  toppings/clams/FrozenClams.h
  toppings/dough/Dough.h
  toppings/dough/ThickCrustDough.h
  toppings/dough/ThinCrustDough.h
  toppings/meat/Meat.h
  toppings/meat/Chicken.h
  toppings/meat/Ham.h
  toppings/meat/Weisswurst.h
  toppings/pepperoni/Pepperoni.h
  toppings/pepperoni/SlicedPepperoni.h
  toppings/sauce/MarinaraSauce.h
  toppings/sauce/PlumTomatoSauce.h
  toppings/sauce/Sauce.h
  toppings/veggies/BlackOlives.h
  toppings/veggies/Eggplant.h
  toppings/veggies/Garlic.h
  toppings/veggies/Mushroom.h
  toppings/veggies/Onion.h
  toppings/veggies/RedPepper.h
  toppings/veggies/Spinach.h
  toppings/veggies/Veggies.h
)
list(TRANSFORM INCLUDE_FILES PREPEND ${CMAKE_CURRENT_LIST_DIR}/)

set(SOURCE_FILES
  PizzaTestDrive.cpp
)
list(TRANSFORM SOURCE_FILES PREPEND ${CMAKE_CURRENT_LIST_DIR}/)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}
  FILES
    ${INCLUDE_FILES}
    ${SOURCE_FILES}
)

set(TARGET_NAME pizza_factory_demo)
add_executable(${TARGET_NAME})

target_include_directories(${TARGET_NAME}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_sources(${TARGET_NAME}
  PRIVATE
    ${INCLUDE_FILES}
    ${SOURCE_FILES}
)

target_compile_features(${TARGET_NAME}
  PRIVATE
    cxx_std_20
)

set_target_properties(${TARGET_NAME} PROPERTIES
  WIN32_EXECUTABLE OFF
)