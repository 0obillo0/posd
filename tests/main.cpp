#include<stdio.h>
#include<iostream>

#include"crop.h"
#include"leaf_vegetable_material_factory.h"
#include"fruit_material_factory.h"
#include"tea_material_factory.h"

int main(){
    cout << "q1" << endl;
    Crop cabbage("cabbage", CropType::LeafVegetable, 12.5);
    Crop strawberry("strawberry", CropType::Fruit, 6.0);
    Crop apple("apple", CropType::FruitTree, 18.0);
    Crop tea("tea",CropType::Tea, 9.5);
    cout << "origin" << endl;
    cabbage.setSprayStrategy(make_unique<WideAreaSpray>());
    strawberry.setSprayStrategy(make_unique<PrecisionSpray>());
    apple.setSprayStrategy(make_unique<CrownSpray>());
    tea.setSprayStrategy(make_unique<MistSpray>());

    cabbage.performSpray();
    strawberry.performSpray();
    apple.performSpray();
    tea.performSpray();
    cout << "after" << endl;
    strawberry.setSprayStrategy(make_unique<MistSpray>());
    strawberry.performSpray();

    LeafVegetableMaterialFactory leafFactory;
    FruitMaterialFactory fruitFactory;
    TeaMaterialFactory teaFactory;

    leafFactory.prepareAndApplyMaterial(cabbage);
    fruitFactory.prepareAndApplyMaterial(strawberry);
    fruitFactory.prepareAndApplyMaterial(apple);
    teaFactory.prepareAndApplyMaterial(tea);


    cout << "q2" << endl;
    cout << "q3" << endl;    
    return 0;
}
