#include"farm_display.h"
#include<iostream>

using namespace std;

void FarmDisplay::update(const string& event, const string& commandName){
    cout << "FarmDisplay: " << commandName << " " << event << "\n";
}