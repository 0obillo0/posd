#include<string>
#include<memory>
#include"spring_spray_configuration.h"
using namespace std;


SpringSprayConfiguration::SpringSprayConfiguration(double  sprayVolume, int sprayIntervalDays, double flightHeight, const string&  configuration): _sprayVolume(sprayVolume), _sprayIntervalDays(sprayIntervalDays), _flightHeight(flightHeight), _configuration(configuration){

}
double SpringSprayConfiguration::getSprayVolume() const{
    return _sprayVolume;
}
int SpringSprayConfiguration::getSprayIntervalDays() const{
    return _sprayIntervalDays;
}
double SpringSprayConfiguration::getFlightHeight() const{
    return _flightHeight;
}
string SpringSprayConfiguration::getConfiguration() const{
    return _configuration;
}
unique_ptr<SprayConfiguration> SpringSprayConfiguration::clone() const{
    return make_unique<SprayConfiguration>(*this);
}