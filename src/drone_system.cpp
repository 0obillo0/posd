#include<iostream>
#include"drone_system.h"

using namespace std;

void DroneSystem::performSpray(){
    cout << "Drone take off." << "\n";
    cout << "Fly to target area." << "\n";
    cout << "Start spraying." << "\n";
    cout << "Return to base." << "\n";
}
void DroneSystem::undoSpray(){
    cout << "Cancel spray record." << "\n";
    cout << "Field restored to unsprayed state." << "\n";
}