#include<string>
#include<memory>
#include"spring_material_factory.h"
#include"spring_fertilizer.h"
#include"spring_pesticide.h"
#include"spring_spray_configuration.h"
using namespace std;

unique_ptr<Fertilizer> SpringMaterialFactory::createFertilizer(const Crop& crop) const{
    return make_unique<SpringFertilizer>();
}
unique_ptr<Pesticide> SpringMaterialFactory::createPesticide(const Crop& crop) const{
    return make_unique<SpringPesticide>();
}
unique_ptr<SprayConfiguration> SpringMaterialFactory::createConfiguration(const Crop& crop) const{
    return make_unique<SpringSprayConfiguration>();
}