#include"farm_scheduler.h"
#include"command.h"
using namespace std;

FarmScheduler& FarmScheduler::instance(){
    static FarmScheduler instance;
    return instance;
}

void FarmScheduler::summit(unique_ptr<Command> command){
    _notificatoinCenter.notify("Command Submitted", command->getName());
    _wattingQueue.push(move(command));
}

void FarmScheduler::runNext(){
    auto command = move(_wattingQueue.front());
    _wattingQueue.pop();
    _notificatoinCenter.notify("Command Started", command->getName());
    command->excute();
    _notificatoinCenter.notify("Command Finished", command->getName());

    _history.push_back(move(command));

    _redoWork.clear();

}

void FarmScheduler::runALL(){
    while (!_wattingQueue.empty()){
        runNext();
    }
}

void FarmScheduler::undo(){
    if(_history.empty()){
        return;
    }
    auto command = move(_history.back());

    _history.pop_back();

    command -> undo();

    _notificatoinCenter.notify("Undo Finished", command->getName());

    _redoWork.push_back(move(command));
}

void FarmScheduler::redo(){
    if(_redoWork.empty()){
        return;
    }
    auto command = move(_redoWork.back());

    _redoWork.pop_back();

    command -> excute();

    _notificatoinCenter.notify("Redo Finished", command->getName());

    _history.push_back(move(command));
}

void FarmScheduler::clear(){
    while (!_wattingQueue.empty()){
        _wattingQueue.pop();
    }
}
NotificationCenter& FarmScheduler::getNotificationCenter(){
    return _notificatoinCenter;
}