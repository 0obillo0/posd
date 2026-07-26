#ifndef SPRAY_CONFIGURATION_H
#define SPRAY_CONFIGURATION_H

#include<string>
#include<memory>
using namespace std;

class SprayConfiguration{
public:
    virtual ~SprayConfiguration() = default;
    virtual double getSprayVolume() const = 0;
    virtual int getSprayIntervalDays() const = 0;
    virtual double getFlightHeight() const = 0;
    virtual string getConfiguration() const = 0;
    virtual unique_ptr<SprayConfiguration> clone() const = 0;
};

#endif
