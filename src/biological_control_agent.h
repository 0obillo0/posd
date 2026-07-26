#ifndef BIOLOGICAL_CONTROL_AGENT_H
#define BIOLOGICAL_CONTROL_AGENT_H

#include"agricultural_material.h"
using namespace std;


class BiologicalControlAgent : public AgriculturalMaterial{
public:
    string getName() const override;
    string getMaterialType() const override;
    string getDescription() const override;
    void apply(double area) const override;
};
#endif