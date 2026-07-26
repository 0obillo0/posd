#include"material_factory.h"
#include<iostream>

using namespace std;

void MaterialFactory::prepareAndApplyMaterial(const Crop& crop) const{
    unique_ptr<AgriculturalMaterial> material = createMaterial();

    cout << "=======================================" << endl;
    cout << crop.getName() << endl;
    cout << material->getName() << endl;
    cout << material->getMaterialType() << endl;
    cout << material->getDescription() << endl;
    material->apply(crop.getArea());
    cout << "=======================================" << endl;
}