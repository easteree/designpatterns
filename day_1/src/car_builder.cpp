#include <iostream>
#include <string>

// Car parts
class Wheel 
{
   private:
    int size;

   public:
    Wheel(int s) 
    { 
    size = s; 
    }

    int getSize() 
    {
        return size; 
    }
};

class Engine 
{
   private:
    int ps;

   public:
    Engine(int p)
    { 
        ps = p; 
    }

    int getPs() 
    { 
        return ps; 
    }
};

class Body 
{
   private:
    std::string shape;

   public:
    Body(std::string s) 
    { 
        shape = s; 
    }

    std::string getShape() 
    { 
        return shape; 
    }
};

// Final product -- a car
class Car 
{
   private:
    Wheel* wheels[4];
    Engine* engine;
    Body* body;

   public:
    void setWheel(Wheel* ws, int index) 
    { 
        wheels[index] = ws; 
    }
    void setEngine(Engine* e) 
    { 
        engine = e; 
    }
    void setBody(Body* b) 
    { 
        body = b; 
    }

    void display() 
    {
        std::cout << "Body:" << body->getShape() << std::endl;
        std::cout << "Engine (PS):" << engine->getPs() << std::endl;
        std::cout << "Tire size:" << wheels[0]->getSize() << "'" << std::endl;
    }
};

// Builder is responsible for constructing the smaller parts
class Builder 
{
   public:
       virtual Body* buildBody() = 0;
       virtual Engine* buildEngine() = 0;
       virtual Wheel* buildWheel() = 0;

       virtual ~Builder() = default;
};

// Director is responsible for the whole process
class Director
{
    Builder* builder = nullptr;

public:
    void setBuilder(Builder* i_builder) {
        builder = i_builder;
    }
    Car* buildCar()
    {
        Car* car = new Car();

        car->setBody(builder->buildBody());

        car->setEngine(builder->buildEngine());

        car->setWheel(builder->buildWheel(), 0);
        car->setWheel(builder->buildWheel(), 1);
        car->setWheel(builder->buildWheel(), 2);
        car->setWheel(builder->buildWheel(), 3);

        return car;
    }

};

// Concrete Builder for SUV cars
class SUVBuilder : public Builder 
{
   private:
    Wheel* wheel;
    Engine* engine;
    Body* body;

   public:
    ~SUVBuilder() 
    {
        delete wheel;
        delete engine;
        delete body;
    }

    Wheel* buildWheel() 
    {
        wheel = new Wheel(22);
        return wheel;
    }

    Engine* buildEngine() 
    {
        engine = new Engine(400);
        return engine;
    }

    Body* buildBody() 
    {
        body = new Body("SUV");
        return body;
    }
};

// Concrete builder for city cars
class CityCarBuilder : public Builder 
{
private:
    Wheel* wheel;
    Engine* engine;
    Body* body;

public:
    ~CityCarBuilder()
    {
        delete wheel;
        delete engine;
        delete body;
    }

    Wheel* buildWheel()
    {
        wheel = new Wheel(16);
        return wheel;
    }

    Engine* buildEngine()
    {
        engine = new Engine(85);
        return engine;
    }

    Body* buildBody()
    {
        body = new Body("Hatchback");
        return body;
    }
};

int main() 
{
    // Final products
    Car* car1 = nullptr;
    Car* car2 = nullptr;

    // Director that controls the process
    Director director;

    // Concrete builders
    SUVBuilder suvBuilder;
    CityCarBuilder ccBuilder;

    // Build an SUV
    std::cout << "SUV" << std::endl;
    director.setBuilder(&suvBuilder);  // using SUVBuilder instance
    car1 = director.buildCar();
    car1->display();

    std::cout << std::endl;

    // Build a City Car
    std::cout << "City Car" << std::endl;
    director.setBuilder(&ccBuilder);  // using CityCarBuilder instance
    car2 = director.buildCar();
    car2->display();

    if (car1 != nullptr) 
        delete car1;

    if (car2 != nullptr) 
        delete car2;

    return 0;
}
