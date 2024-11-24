#include <sstream>
#include "GPS.hpp"

namespace {
    class GPS_Exception : public std::exception
    {
    public:
        GPS_Exception(std::string msg) : m_msg{ msg } {}
        const char* what() const throw() override
        {
            return m_msg.c_str();
        }

    private:
        std::string m_msg;
    };


}

namespace design_pattern{
    GPS GPS::fromLine(const std::string & str) {
        double lat, lon;
        char delimiter;

        std::istringstream i_stream(str);

        if (i_stream >> lat >> delimiter >> lon && delimiter == ',') {
            return GPS(lat, lon);
        }

        throw GPS_Exception("FAILURE: GPS::fromLine: \"" + str + "\"");
    }

    std::ostream& operator<<(std::ostream& os, const GPS& gps) {
        return os << "GPS(lat:" << gps.lat << ",lon:" << gps.lon <<")";
    }
}

