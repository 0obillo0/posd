#ifndef LEAF_VEGETABLE_FERTILIZER_H
#define LEAF_VEGETABLE_FERTILIZER_H

#include"agricultural_material.h"
using namespace std;


class LeafVegetableFertilizer : public AgriculturalMaterial{
public:
    string getName() const override;
    string getMaterialType() const override;
    string getDescription() const override;
    void apply(double area) const override;
};

#endif