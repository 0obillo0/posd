
#ifndef MOBILE_APP_H
#define MOBILE_APP_H

#include<string>
#include"observer.h"
using namespace std;

class MobileAPP : public Observer{
public:
    void update(const string& event, const string& commandName) override; 
};

#endif