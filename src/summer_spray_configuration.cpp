#include<string>
#include<memory>
#include"summer_spray_configuration.h"
using namespace std;


SummerSprayConfiguration::SummerSprayConfiguration(double  sprayVolume, int sprayIntervalDays, double flightHeight, const string&  configuration): _sprayVolume(sprayVolume), _sprayIntervalDays(sprayIntervalDays), _flightHeight(flightHeight), _configuration(configuration){

}
double SummerSprayConfiguration::getSprayVolume() const{
    return _sprayVolume;
}
int SummerSprayConfiguration::getSprayIntervalDays() const{
    return _sprayIntervalDays;
}
double SummerSprayConfiguration::getFlightHeight() const{
    return _flightHeight;
}
string SummerSprayConfiguration::getConfiguration() const{
    return _configuration;
}
unique_ptr<SprayConfiguration> SummerSprayConfiguration::clone() const{
    return make_unique<SummerSprayConfiguration>(*this);
}