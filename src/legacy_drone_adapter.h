#ifndef LEGACY_DRONE_ADAPTER_H
#define LEGACY_DRONE_ADAPTER_H

#include<memory>
#include"drone.h"
#include"legacy_drone.h"

using namespace std;

class LegacyDroneAdapter: public Drone{
private:
    unique_ptr<LegacyDrone> _legacyDrone;
    bool _materialLoaded = false;
public:
    explicit LegacyDroneAdapter(unique_ptr<LegacyDrone> drone);
    void loadMaterial(const SprayConfiguration& config) override;
    void flyTo(double x, double y) override;
    void spray() override;
};
#endif