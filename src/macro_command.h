#ifndef MACRO_COMMAND_H
#define MACRO_COMMAND_H

#include<vector>
#include<memory>
#include"command.h"

using namespace std;

class MacroCommand : public Command{
private:
    string _name;
    vector<unique_ptr<Command>> _commands;
public:
    explicit MacroCommand(const string& name);
    void addCommand(unique_ptr<Command> Command);
    void excute() override;
    void undo() override;
    string getName() override;
    
};

#endif