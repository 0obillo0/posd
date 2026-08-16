#ifndef NOTIFICATION_CENTER_H
#define NOTIFICATION_CENTER_H

#include<vector>
#include<memory>
#include"observer.h"

using namespace std;

class NotificationCenter{
private:
    vector<Observer*> _observers;
public:
    void attach(Observer* observer);
    void detach(Observer* observer);
    void notify(const string& envent, const string& commandName);
    int observerCount() const;
};

#endif