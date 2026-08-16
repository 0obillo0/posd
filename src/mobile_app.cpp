#include"mobile_app.h"
#include<iostream>

using namespace std;

void MobileAPP::update(const string& event, const string& commandName){
    cout << "MobileAPP: " << commandName << " " << event << "\n";
}