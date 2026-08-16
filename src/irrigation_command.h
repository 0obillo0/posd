#ifndef IRRIGATION_COMMAND_H
#define IRRIGATION_COMMAND_H


#include"command.h"

using namespace std;

class IrrigationSystem;

class IrrigationCommand : public Command{
private:
    IrrigationSystem* _receiver;
public:
    explicit IrrigationCommand(IrrigationSystem* receiver);
    void excute() override;
    void undo() override;
    string getName() override;
    
};

#endif