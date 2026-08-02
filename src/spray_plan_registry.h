#ifndef SPRAY_PLAN_REGISTRY_H
#define SPRAY_PLAN_REGISTRY_H

#include<string>
#include<memory>
#include"spray_plan_prototype.h"

using namespace std;

class SprayPlanRegistry{
public:
    void registerProtype(const string& key, unique_ptr<SprayPlanPrototype>);
    unique_ptr<SprayPlanPrototype> createPlan(const string& key) const;
};

#endif