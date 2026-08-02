
#ifndef WINTER_SPRAY_CONFIGURATION_H
#define WINTER_SPRAY_CONFIGURATION_H

#include<string>
#include<memory>
#include"spray_configuration.h"
using namespace std;

class WinterSprayConfiguration : public SprayConfiguration{
private:
    double _sprayVolume;
    int _sprayIntervalDays;
    double _flightHeight;
    string _configuration; 
public:
    WinterSprayConfiguration(double sprayVolume = 0.0, int sprayIntervalDays = 0, double flightHeight = 0.0 , const string&  configuration="winter");
    double getSprayVolume() const override;
    int getSprayIntervalDays() const override;
    double getFlightHeight() const override;
    string getConfiguration() const override;
    unique_ptr<SprayConfiguration> clone() const override;
};

#endif