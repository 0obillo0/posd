#include"macro_command.h"

using namespace std;


MacroCommand::MacroCommand(const string& name):_name(name){
}

void MacroCommand::addCommand(unique_ptr<Command> command){
    _commands.push_back(move(command));
}

void MacroCommand::excute(){
    for (auto& command : _commands){
        command->excute();
    }
    
}

void MacroCommand::undo(){
    for(auto it = _commands.rbegin();it != _commands.rend(); it++){
        (*it)->undo();
    }
}

string MacroCommand::getName(){
    return _name;
}