#ifndef STATIONS_HPP
#define STATIONS_HPP

#include "devices.hpp"

enum class Station {
    NONE,
    STATION_A,
    STATION_B,
    STATION_C,
    STATION_D
};

void runStationA();
void runStationB();

#endif // STATIONS_HPP
