#include<iostream>
#include"legacy_drone.h"

using namespace std;


void LegacyDrone::setChemicalDate(double chemicalRate){
    cout << "Set Chemical Date" << chemicalRate << "\n";
}
void LegacyDrone::moveToLocation(const string& location){
    cout << "Move To Location" << location << "\n";
}
void LegacyDrone::startChemicalRelease(){
    cout << "Start Chemical Release" << "\n";
}