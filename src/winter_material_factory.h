#ifndef WINTER_MATERIAL_FACTORY_H
#define WINTER_MATERIAL_FACTORY_H

#include<string>
#include<memory>

#include"seasonal_material_factory.h"
using namespace std;

class WinterMaterialFactory :public SeasonalMaterialFactory{
public:
    unique_ptr<Fertilizer> createFertilizer(const Crop& crop) const override;
    unique_ptr<Pesticide> createPesticide(const Crop& crop) const override;
    unique_ptr<SprayConfiguration> createConfiguration(const Crop& crop) const override;
};

#endif

