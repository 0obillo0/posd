#include"fruit_material_factory.h"
#include"fruit_pesticide.h"

using namespace std;

unique_ptr<AgriculturalMaterial> FruitMaterialFactory::createMaterial() const{
    return make_unique<FruitPesticide>();
}