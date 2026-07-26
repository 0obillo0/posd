
#ifndef SPRING_SPRAY_CONFIGURATION_H
#define SPRING_SPRAY_CONFIGURATION_H

#include<string>
#include<memory>
#include"spray_configuration.h"
using namespace std;

class SpringSprayConfiguration : public SprayConfiguration{
private:
    double _sprayVolume;
    int _sprayIntervalDays;
    double _flightHeight;
    string _configuration; 
public:
    SpringSprayConfiguration(double sprayVolume, int sprayIntervalDays, double flightHeight, const string&  configuration);
    double getSprayVolume() const override;
    int getSprayIntervalDays() const override;
    double getFlightHeight() const override;
    string getConfiguration() const override;
    unique_ptr<SprayConfiguration> clone() const override;
};

#endif