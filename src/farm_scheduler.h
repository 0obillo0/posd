#ifndef FARM_SCHEDULER_H
#define FARM_SCHEDULER_H

#include<vector>
#include<memory>
#include<queue>
#include"notification_center.h"

using namespace std;

class Command;

class FarmScheduler{
private:
    queue<unique_ptr<Command>> _wattingQueue;
    vector<unique_ptr<Command>> _history;
    vector<unique_ptr<Command>> _redoWork;
    NotificationCenter _notificatoinCenter;
    
    FarmScheduler() = default;
    
public:
    static FarmScheduler& instance();

    FarmScheduler(const FarmScheduler&) = delete;
    FarmScheduler& operator=(const FarmScheduler&) = delete;
    
    void summit(unique_ptr<Command> command);
    void runNext();
    void runALL();
    void undo();
    void redo();
    void clear();
    NotificationCenter& getNotificationCenter();
};

#endif