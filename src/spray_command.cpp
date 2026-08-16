#include"spray_command.h"
#include"drone_system.h"

using namespace std;

SprayCommand::SprayCommand(DroneSystem* receiver):_receiver(receiver){
}
void SprayCommand::excute(){
    _receiver->performSpray();
}
void SprayCommand::undo(){
    _receiver->undoSpray();
}
string SprayCommand::getName() {
    return "SprayCommand";
}