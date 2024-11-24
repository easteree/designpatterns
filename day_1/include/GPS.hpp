#pragma once

#include <ostream>

namespace design_pattern{

    class GPS {
        double lat, lon;
        GPS(double lat, double lon) : lat{ lat }, lon{ lon }{}
    public:
        static GPS fromLine(const std::string & str);
        friend std::ostream& operator<<(std::ostream& os, const GPS& gps);

    };

}