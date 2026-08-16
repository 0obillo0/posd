#ifndef COMMAND_H
#define COMMAND_H

#include<string>
using namespace std;

class Command{
public:
    virtual ~Command() = default;
    virtual void excute() = 0;
    virtual void undo() = 0;
    virtual string getName() = 0;
    
};

#endif