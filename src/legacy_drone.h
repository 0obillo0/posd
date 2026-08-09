#ifndef LEGACY_DRONE_H
#define LEGACY_DRONE_H

#include<string>
using namespace std;


class LegacyDrone{
public:
    void setChemicalDate(double chemicalRate);
    void moveToLocation(const string& location);
    void startChemicalRelease();
};
#endif