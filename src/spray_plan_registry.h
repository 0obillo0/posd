#ifndef SPRAY_PLAN_REGISTRY_H
#define SPRAY_PLAN_REGISTRY_H

#include<string>
#include<memory>
#include<unordered_map>
#include"spray_plan_prototype.h"

using namespace std;

class SprayPlanRegistry{
private:
    unordered_map<string, unique_ptr<SprayPlanPrototype>> _prototype;
public:
    void registerProtype(const string& key, unique_ptr<SprayPlanPrototype>);
    unique_ptr<SprayPlanPrototype> createPlan(const string& key) const;
};

#endif