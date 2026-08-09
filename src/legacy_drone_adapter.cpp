#include<iostream>
#include<stdexcept>
#include"legacy_drone_adapter.h"


using namespace std;

LegacyDroneAdapter::LegacyDroneAdapter(unique_ptr<LegacyDrone> drone): _legacyDrone(move(drone)){
}

void LegacyDroneAdapter::loadMaterial(const SprayConfiguration& config){
    _legacyDrone->setChemicalDate(config.getSprayVolume());
    _materialLoaded = true;
}

void LegacyDroneAdapter::flyTo(double x, double y){
    string location = "A" + to_string(x) + "-B" + to_string(y);
    _legacyDrone->moveToLocation(location);
}
void LegacyDroneAdapter::spray(){
    if(!_materialLoaded){
        throw runtime_error{
            "Material not been loaded"
        };
    }
    _legacyDrone->startChemicalRelease();
}