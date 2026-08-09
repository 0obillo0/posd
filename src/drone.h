#ifndef DRONE_H
#define DRONE_H

#include"spray_configuration.h"

class Drone{
public:
    virtual ~Drone() = default;
    virtual void loadMaterial(const SprayConfiguration& config) = 0;
    virtual void flyTo(double x, double y) = 0;
    virtual void spray() = 0;
};
#endif