#include"sensor_command.h"
#include"sensor_system.h"

using namespace std;

SensorCommand::SensorCommand(SensorSystem* receiver):_receiver(receiver){
}
void SensorCommand::excute(){
    _receiver->performSensor();
}
void SensorCommand::undo(){
    _receiver->undoSensor();
}
string SensorCommand::getName() {
    return "SensorCommand";
}