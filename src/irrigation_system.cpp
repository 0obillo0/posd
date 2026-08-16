#include<iostream>
#include"irrigation_system.h"

using namespace std;

void IrrigationSystem::performIrrigation(){
    cout << "Open irrigation system." << "\n";
    cout << "set water flow." << "\n";
    cout << "Irrigation completed." << "\n";
}
void IrrigationSystem::undoIrrigation(){
    cout << "Stop irrigation." << "\n";
    cout << "Restore Previous setting." << "\n";
}