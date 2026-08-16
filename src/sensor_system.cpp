#include<iostream>
#include"sensor_system.h"

using namespace std;

void SensorSystem::performSensor(){
    cout << "Read sensor data." << "\n";
    cout << "Update database" << "\n";
}

void SensorSystem::undoSensor(){
    cout << "Restore previous sensor data." << "\n";
}