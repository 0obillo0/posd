#ifndef FRUIT_MATERIAL_FACTORY_H
#define FRUIT_MATERIAL_FACTORY_H

#include"material_factory.h"

using namespace std;

class FruitMaterialFactory : public MaterialFactory{
public:
    unique_ptr<AgriculturalMaterial> createMaterial() const override;
};

#endif