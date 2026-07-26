#include"tea_material_factory.h"
#include"biological_control_agent.h"

using namespace std;

unique_ptr<AgriculturalMaterial> TeaMaterialFactory::createMaterial() const{
    return make_unique<BiologicalControlAgent>();
}