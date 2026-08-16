#ifndef SENSOR_COMMAND_H
#define SENSOR_COMMAND_H


#include"command.h"

using namespace std;

class SensorSystem;

class SensorCommand : public Command{
private:
    SensorSystem* _receiver;
public:
    explicit SensorCommand(SensorSystem* receiver);
    void excute() override;
    void undo() override;
    string getName() override;
    
};

#endif