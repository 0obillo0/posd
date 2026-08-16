#ifndef FERTILIZE_COMMAND_H
#define FERTILIZE_COMMAND_H


#include"command.h"

using namespace std;

class FertilizeSystem;

class FertilizeCommand : public Command{
private:
    FertilizeSystem* _receiver;
public:
    explicit FertilizeCommand(FertilizeSystem* receiver);
    void excute() override;
    void undo() override;
    string getName() override;
    
};

#endif