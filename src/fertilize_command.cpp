
#include"fertilize_command.h"
#include"fertilize_system.h"

using namespace std;

FertilizeCommand::FertilizeCommand(FertilizeSystem* receiver):_receiver(receiver){
}
void FertilizeCommand::excute(){
    _receiver->performFertilize();
}
void FertilizeCommand::undo(){
    _receiver->undoFertilize();
}
string FertilizeCommand::getName() {
    return "FertilizeCommand";
}