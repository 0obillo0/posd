#include"leaf_vegetable_material_factory.h"
#include"leaf_vegetable_fertilizer.h"

using namespace std;

unique_ptr<AgriculturalMaterial> LeafVegetableMaterialFactory::createMaterial() const{
    return make_unique<LeafVegetableFertilizer>();
}