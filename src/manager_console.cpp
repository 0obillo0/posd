
#include"manager_console.h"
#include<iostream>

using namespace std;

void ManagerConsole::update(const string& event, const string& commandName){
    cout << "ManagerConsole: " << commandName << " " << event << "\n";
}