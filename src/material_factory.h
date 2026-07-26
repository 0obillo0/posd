#ifndef MATERIAL_FACTORY_H
#define MATERIAL_FACTORY_H

#include<memory>
#include"agricultural_material.h"
#include"crop.h"

using namespace std;

class MaterialFactory{
public:
    virtual ~MaterialFactory() = default;
    virtual unique_ptr<AgriculturalMaterial> createMaterial() const = 0;
    void prepareAndApplyMaterial(const Crop &crop) const;
};

#endif
