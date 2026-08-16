#ifndef SPRAY_COMMAND_H
#define SPRAY_COMMAND_H


#include"command.h"

using namespace std;

class DroneSystem;

class SprayCommand : public Command{
private:
    DroneSystem* _receiver;
public:
    explicit SprayCommand(DroneSystem* receiver);
    void excute() override;
    void undo() override;
    string getName() override;
    
};

#endif