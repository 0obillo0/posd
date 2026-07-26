#ifndef FRUIT_PESTICIDE_H
#define FRUIT_PESTICIDE_H

#include"agricultural_material.h"
using namespace std;


class FruitPesticide : public AgriculturalMaterial{
public:
    string getName() const override;
    string getMaterialType() const override;
    string getDescription() const override;
    void apply(double area) const override;
};

#endif