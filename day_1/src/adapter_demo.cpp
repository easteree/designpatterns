#include <iostream>

// a class containing only pure virtual methods ≙ interface
// - this is the legacy interface that shall not be changed
class ThermoInterface
{
    public:
        virtual double getTempC() = 0;
        virtual ~ThermoInterface() = default;
};

// Legacy component
// - this compoment is broken and shall be replaced
class CelciusThermo : public ThermoInterface
{
    public:
        double getTempC() override
        {
            return -20;
        }
    
};


namespace design_pattern::adapter {
    class FahrenheitThermo
    {
    public:
        double getFahrenheitTemperature()
        {
            return -4; // -4 °F should be -20° C
        }

    };


    class CelciusThermo : public ThermoInterface {
    public:

        double getTempC() override {
            return (m_fahrenheit.getFahrenheitTemperature() - 32.) * 5. / 9.;
        }

    private:
        FahrenheitThermo m_fahrenheit{};
    };

}


int main()
{
    using ThermoAdapter = design_pattern::adapter::CelciusThermo;

    auto ti = std::make_unique<ThermoAdapter>();
    std::cout << ti->getTempC() << std::endl;

}
