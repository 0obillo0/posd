#include"notification_center.h"
#include"observer.h"
#include<algorithm>

using namespace std;
    
void NotificationCenter::attach(Observer* observer){
    auto it = find(_observers.begin(),_observers.end(),observer);
    if(it == _observers.end()){
        _observers.push_back(observer);
    }
}

void NotificationCenter::detach(Observer* observer){
    auto it = find(_observers.begin(),_observers.end(),observer);
    if(it != _observers.end()){
        _observers.erase(it);
    }
}

void NotificationCenter::notify(const string& envent, const string& commandName){
    for(Observer* observer : _observers){
        observer->update(envent, commandName);
    }
}

int NotificationCenter::observerCount() const{
    return _observers.size();
}