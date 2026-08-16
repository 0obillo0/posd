
#ifndef MANAGER_CONSOLE_H
#define MANAGER_CONSOLE_H

#include<string>
#include"observer.h"
using namespace std;

class ManagerConsole : public Observer{
public:
    void update(const string& event, const string& commandName) override; 
};

#endif