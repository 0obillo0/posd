#ifndef SPRAY_PLAN_PROTOTYPE_H
#define SPRAY_PLAN_PROTOTYPE_H

#include<string>
#include<memory>

using namespace std;

class SprayPlanPrototype{
public:
    virtual ~SprayPlanPrototype() = default;
    virtual unique_ptr<SprayPlanPrototype> clone() const = 0;
};
#endif