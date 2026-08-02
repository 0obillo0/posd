#include<string>
#include<memory>
#include"winter_material_factory.h"
#include"winter_fertilizer.h"
#include"winter_pesticide.h"
#include"winter_spray_configuration.h"
using namespace std;

unique_ptr<Fertilizer> WinterMaterialFactory::createFertilizer(const Crop& crop) const{
    return make_unique<WinterFertilizer>();
}
unique_ptr<Pesticide> WinterMaterialFactory::createPesticide(const Crop& crop) const{
    return make_unique<WinterPesticide>();
}
unique_ptr<SprayConfiguration> WinterMaterialFactory::createConfiguration(const Crop& crop) const{
    return make_unique<WinterSprayConfiguration>();    
}