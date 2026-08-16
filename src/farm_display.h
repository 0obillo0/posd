
#ifndef FARM_DISPLAY_H
#define FARM_DISPLAY_H

#include<string>
#include"observer.h"
using namespace std;

class FarmDisplay : public Observer{
public:
    void update(const string& event, const string& commandName) override; 
};

#endif