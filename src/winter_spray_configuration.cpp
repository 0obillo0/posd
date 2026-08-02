#include<string>
#include<memory>
#include"winter_spray_configuration.h"
using namespace std;


WinterSprayConfiguration::WinterSprayConfiguration(double  sprayVolume, int sprayIntervalDays, double flightHeight, const string&  configuration): _sprayVolume(sprayVolume), _sprayIntervalDays(sprayIntervalDays), _flightHeight(flightHeight), _configuration(configuration){

}
double WinterSprayConfiguration::getSprayVolume() const{
    return _sprayVolume;
}
int WinterSprayConfiguration::getSprayIntervalDays() const{
    return _sprayIntervalDays;
}
double WinterSprayConfiguration::getFlightHeight() const{
    return _flightHeight;
}
string WinterSprayConfiguration::getConfiguration() const{
    return _configuration;
}
unique_ptr<SprayConfiguration> WinterSprayConfiguration::clone() const{
    return make_unique<WinterSprayConfiguration>(*this);
}