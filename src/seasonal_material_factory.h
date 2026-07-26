#ifndef SEASONAL_MATERIAL_FACTORY_H
#define SEASONAL_MATERIAL_FACTORY_H

#include<string>
#include<memory>
#include"crop.h"
#include"fertilizer.h"
#include"pesticide.h"
#include"spray_configuration.h"
using namespace std;

class SeasonalMaterialFactory{
public:
    virtual ~SeasonalMaterialFactory() = default;
    virtual unique_ptr<Fertilizer> createFertilizer(const Crop& crop) const = 0;
    virtual unique_ptr<Pesticide> createPesticide(const Crop& crop) const = 0;
    virtual unique_ptr<SprayConfiguration> createConfiguration(const Crop& crop) const = 0;
};

#endif

