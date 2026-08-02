#include<string>
#include<memory>
#include<iostream>
#include"spray_plan_registry.h"

using namespace std;

void SprayPlanRegistry::registerProtype(const string& key, unique_ptr<SprayPlanPrototype> prototype){
    if(!prototype){
        throw invalid_argument("null");
    }
    if(_prototype.find(key) != _prototype.end()){
        cout << "already exists";
    }
    _prototype[key] = move(prototype);
}
unique_ptr<SprayPlanPrototype> SprayPlanRegistry::createPlan(const string& key) const{
    auto it = _prototype.find(key);

    if(it == _prototype.end()){
        throw out_of_range("not have this key");
    }

    return it->second->clone();
}