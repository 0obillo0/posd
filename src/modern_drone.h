#ifndef MODERN_DRONE_H
#define MODERN_DRONE_H

#include"drone.h"

class ModernDrone: public Drone{
private:
    bool _materiaLoaded = false;
public:
    void loadMaterial(const SprayConfiguration& config) override;
    void flyTo(double x, double y) override;
    void spray() override;
};
#endif