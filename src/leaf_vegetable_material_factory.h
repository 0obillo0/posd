#ifndef LEAF_VEGETABLE_MATERIAL_FACTORY_H
#define LEAF_VEGETABLE_MATERIAL_FACTORY_H
#include"material_factory.h"

using namespace std;

class LeafVegetableMaterialFactory : public MaterialFactory{
public:
    unique_ptr<AgriculturalMaterial> createMaterial() const override;
};
#endif