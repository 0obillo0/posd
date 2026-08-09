#include<iostream>
#include"modern_drone.h"

using namespace std;

void ModernDrone::loadMaterial(const SprayConfiguration& config){
    _materiaLoaded = true;
    cout << "load Material" << "\n";
}
void ModernDrone::flyTo(double x, double y){
    cout << "ModernDrone Fly To" << x << "," << y << "\n";
}
void ModernDrone::spray(){
    if(_materiaLoaded){
        cout << "ModernDrone Spraying" << "\n";
    }else{
        cout << "ModernDrone Not Spraying" << "\n";
    }
}