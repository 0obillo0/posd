#include<stdio.h>
#include<iostream>

#include"crop.h"
#include"leaf_vegetable_material_factory.h"
#include"fruit_material_factory.h"
#include"tea_material_factory.h"


#include"spring_material_factory.h"
#include"summer_material_factory.h"
#include"winter_material_factory.h"
#include"compatibility_valaidator.h"
#include"spray_plan.h"
#include"spray_plan_registry.h"
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
    SpringMaterialFactory springFactory;
    SummerMaterialFactory summerFactory;
    WinterMaterialFactory winterFactory;


    auto springFert = springFactory.createFertilizer(cabbage);
    auto springPest = springFactory.createPesticide(cabbage);
    auto springConfig = springFactory.createConfiguration(cabbage);

    auto summerFert = summerFactory.createFertilizer(strawberry);
    auto summerPest = summerFactory.createPesticide(strawberry);
    auto summerConfig = summerFactory.createConfiguration(strawberry);

    auto winterFert = winterFactory.createFertilizer(apple);
    auto winterPest = winterFactory.createPesticide(apple);
    auto winterConfig = winterFactory.createConfiguration(apple);

    cout << "spring: "<< (CompatibilityValaidator::validateCompatibility(*springFert, *springPest, *springConfig) ? "pass" : "fail") << "\n" ;
    cout << "summer: "<< (CompatibilityValaidator::validateCompatibility(*summerFert, *summerPest, *summerConfig) ? "pass" : "fail") << "\n" ;
    cout << "winter:"<< (CompatibilityValaidator::validateCompatibility(*winterFert, *winterPest, *winterConfig) ? "pass" : "fail") << "\n" ;
    cout << "fail: "<< (CompatibilityValaidator::validateCompatibility(*springFert, *summerPest, *winterConfig) ? "pass" : "fail") << "\n" ;

    auto springCabbagePlan = make_unique<SprayPlan>("Spring Cabbage plan", "Cabbage", Season::Spring,move(springFert), move(springPest), move(springConfig));
    springCabbagePlan->addRoute("Cabbage-A1");
    springCabbagePlan->addRoute("Cabbage-A2");
    springCabbagePlan->addRoute("Cabbage-A3");
    springCabbagePlan->addExecutionHour(6);
    springCabbagePlan->addExecutionHour(7);
    springCabbagePlan->addExecutionHour(17);

    auto summerStrawberryPlan = make_unique<SprayPlan>("Summer Strawberry plan", "strawberry", Season::Summer,move(summerFert), move(summerPest), move(summerConfig));
    summerStrawberryPlan->addRoute("Strawberry-B1");
    summerStrawberryPlan->addRoute("Strawberry-B2");
    summerStrawberryPlan->addRoute("Strawberry-B3");
    summerStrawberryPlan->addExecutionHour(5);
    summerStrawberryPlan->addExecutionHour(6);
    summerStrawberryPlan->addExecutionHour(18);

    auto winterApplePlan = make_unique<SprayPlan>("Winter Apple plan", "apple", Season::Winter,move(winterFert), move(winterPest), move(winterConfig));
    winterApplePlan->addRoute("Apple-C1");
    winterApplePlan->addRoute("Apple-C2");
    winterApplePlan->addRoute("Apple-C3");
    winterApplePlan->addExecutionHour(8);
    winterApplePlan->addExecutionHour(9);
    winterApplePlan->addExecutionHour(15);

    SprayPlanRegistry registry;
    registry.registerProtype("SpringCabbage", move(springCabbagePlan));
    registry.registerProtype("SummerStrawberry", move(summerStrawberryPlan));
    registry.registerProtype("WinterApple", move(winterApplePlan));

    auto clonePrototype = registry.createPlan("SummerStrawberry");
    auto organicStrawberryPlan = dynamic_cast<SprayPlan*>(clonePrototype.get());

    organicStrawberryPlan->setPlanName("Organic Strawberry Area Plan");
    organicStrawberryPlan->addRoute("Organic-Strawberry_B4");
    organicStrawberryPlan->addWarning("ban chemical");
    organicStrawberryPlan->removeExecutionHour(18);
    organicStrawberryPlan->addExecutionHour(19);
    organicStrawberryPlan->setRequiresManagerApproval(true);


    auto organicStrawberryRef = registry.createPlan("SummerStrawberry");
    auto orginPlan = dynamic_cast<SprayPlan*>(organicStrawberryRef.get());
    
    orginPlan->printPlan();

    organicStrawberryPlan->printPlan();

    cout << "orginal plan:"<< static_cast<const void*>(orginPlan) << "\n" ;
    cout << "after plan:"<< static_cast<const void*>(organicStrawberryPlan) << "\n" ;

    cout << "q3" << endl;
    cout << "q4" << endl;   
    cout << "q5" << endl;
    cout << "q6" << endl;
    cout << "q7" << endl;        

    return 0;
}
