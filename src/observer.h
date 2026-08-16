#ifndef OBSERVER_H
#define OBSERVER_H

#include<string>
using namespace std;

class Observer{
public:
    virtual ~Observer() = default;
    virtual void update(const string& event, const string& commandName) = 0; 
};

#endif