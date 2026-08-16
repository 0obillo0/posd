#include"irrigation_command.h"
#include"irrigation_system.h"

using namespace std;

IrrigationCommand::IrrigationCommand(IrrigationSystem* receiver):_receiver(receiver){
}
void IrrigationCommand::excute(){
    _receiver->performIrrigation();
}
void IrrigationCommand::undo(){
    _receiver->undoIrrigation();
}
string IrrigationCommand::getName() {
    return "IrrigationCommand";
}