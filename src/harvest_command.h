#ifndef HARVEST_COMMAND_H
#define HARVEST_COMMAND_H


#include"command.h"

using namespace std;

class HarvestSystem;

class HarvestCommand : public Command{
private:
    HarvestSystem* _receiver;
public:
    explicit HarvestCommand(HarvestSystem* receiver);
    void excute() override;
    void undo() override;
    string getName() override;
    
};

#endif