#include<string>
#include<memory>
#include"summer_material_factory.h"
#include"summer_fertilizer.h"
#include"summer_pesticide.h"
#include"summer_spray_configuration.h"
using namespace std;

unique_ptr<Fertilizer> SummerMaterialFactory::createFertilizer(const Crop& crop) const{
    return make_unique<SummerFertilizer>();
}
unique_ptr<Pesticide> SummerMaterialFactory::createPesticide(const Crop& crop) const{
    return make_unique<SummerPesticide>();
}
unique_ptr<SprayConfiguration> SummerMaterialFactory::createConfiguration(const Crop& crop) const{
    return make_unique<SummerSprayConfiguration>();
}