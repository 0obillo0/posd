#include"harvest_command.h"
#include"harvest_system.h"

using namespace std;

HarvestCommand::HarvestCommand(HarvestSystem* receiver):_receiver(receiver){
}
void HarvestCommand::excute(){
    _receiver->performHarvest();
}
void HarvestCommand::undo(){
    _receiver->undoHarvest();
}
string HarvestCommand::getName() {
    return "HarvestCommand";
}