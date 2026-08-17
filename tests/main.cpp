#include<stdio.h>
#include<iostream>
#include<memory>

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
#include"spring_spray_configuration.h"

#include"drone.h"
#include"modern_drone.h"
#include"legacy_drone.h"
#include"legacy_drone_adapter.h"
#include"farm_area.h"
#include"crop_field.h"
#include"field_iterator.h"

#include"farm_scheduler.h"
#include"drone_system.h"
#include"irrigation_system.h"
#include"fertilize_system.h"
#include"harvest_system.h"
#include"sensor_system.h"
#include"spray_command.h"
#include"irrigation_command.h"
#include"fertilize_command.h"
#include"harvest_command.h"
#include"sensor_command.h"
#include"macro_command.h"
#include"farm_display.h"
#include"manager_console.h"
#include"mobile_app.h"
#include"audit_log.h"

#include"concreted_drink_builder.h"
#include"drink_director.h"
#include"fruit_tea_prepartion.h"
#include"fresh_fruit_decorator.h"
#include"honey_decorator.h"
#include"cheese_foam_decorator.h"


int main(){
    
    cout << "----------------------------------------------" << endl;
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

    cout << "----------------------------------------------" << endl;
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
    
    cout << "----------------------------------------------" << endl;
    cout << "q3" << endl;
    SpringSprayConfiguration config(2.55,7,5.0,"spring");
    ModernDrone modernDrone;

    auto legacyDrone1 = make_unique<LegacyDrone>();
    auto legacyDrone2 = make_unique<LegacyDrone>();

    LegacyDroneAdapter legacyAdapter1(move(legacyDrone1));
    LegacyDroneAdapter legacyAdapter2(move(legacyDrone2));

    auto farm = make_unique<FarmArea>("Taiwin Smart Farm");
    auto northOrchard = make_unique<FarmArea>("North Orchard");
    auto southVegetableFarm = make_unique<FarmArea>("South Vegetable Farm");
    auto teaGarden = make_unique<FarmArea>("Tea Garden");

    northOrchard->add(make_unique<CropField>("Apple Area", "Apple", 2.5, 10, 25, "Flowering"));
    northOrchard->add(make_unique<CropField>("Pear Area", "Pear", 2.0, 15, 30, "Growing"));
    northOrchard->add(make_unique<CropField>("Peach Area", "Peach", 1.8, 20, 35, "Flowering"));

    southVegetableFarm->add(make_unique<CropField>("Cabbage Area", "Cabbage", 1.6, 21, 36, "Growing"));
    southVegetableFarm->add(make_unique<CropField>("Tomato Area", "Tomato", 2.7, 16, 32, "Fruiting"));
    southVegetableFarm->add(make_unique<CropField>("Lettuce Area", "Lettuce", 1.3, 14, 33, "Growing"));

    teaGarden->add(make_unique<CropField>("Black Tea Area", "Black Tea", 1.5, 40, 12, "Growing"));
    teaGarden->add(make_unique<CropField>("Red Tea Area", "Red Tea", 3.0, 16, 31, "Growing"));

    FarmArea* northOrchardPtr = northOrchard.get();

    farm->add(move(northOrchard));
    farm->add(move(southVegetableFarm));
    farm->add(move(teaGarden));

    auto northIterator = northOrchardPtr->createIterator();

    northIterator->first();
    while (northIterator->hasNext()){
        CropField* field = northIterator->current();
        cout << "Spraying: " << field->getName() << "\n";
        modernDrone.loadMaterial(config);
        modernDrone.flyTo(field->getX(), field->getY());
        modernDrone.spray();
        
        field->setSprayed(true);

        northIterator->next();
    }
    
    auto farmIterator = farm->createIterator();
    farmIterator->first();

    while (farmIterator->hasNext()){
        CropField* field = farmIterator->current();
        field->display();
        farmIterator->next();
    }



    auto legacyIterator = northOrchardPtr->createIterator();

    legacyIterator->first();

    Drone& drone = legacyAdapter1;
    
    while (legacyIterator->hasNext()){
        CropField* field = legacyIterator->current();
        cout << "Spraying: " << field->getName() << "\n";
        drone.loadMaterial(config);
        drone.flyTo(field->getX(), field->getY());
        drone.spray();
        
        field->setSprayed(true);

        legacyIterator->next();
    }
    cout << "----------------------------------------------" << endl;
    cout << "q4" << endl;
    
    FarmScheduler& scheduler = FarmScheduler::instance();

    DroneSystem droneSystem;
    IrrigationSystem irrigationSystem;
    HarvestSystem harvestSystem;
    SensorSystem sensorSystem;
    FertilizeSystem fertilizeSystem;

    auto sprayCommand = make_unique<SprayCommand>(&droneSystem);
    auto harvestCommand = make_unique<HarvestCommand>(&harvestSystem);
    auto sensorCommand = make_unique<SensorCommand>(&sensorSystem);

    auto morningRoutine = make_unique<MacroCommand>("Morning Routine");
    morningRoutine->addCommand(make_unique<SprayCommand>(&droneSystem));
    morningRoutine->addCommand(make_unique<SensorCommand>(&sensorSystem));
    morningRoutine->addCommand(make_unique<IrrigationCommand>(&irrigationSystem));
    morningRoutine->addCommand(make_unique<FertilizeCommand>(&fertilizeSystem));

    FarmDisplay farmDisplay;
    ManagerConsole managerConsole;
    MobileAPP mobileAPP;
    AuditLog auditLog;

    NotificationCenter& notificationCenter = scheduler.getNotificationCenter();

    notificationCenter.attach(&farmDisplay);
    notificationCenter.attach(&managerConsole);
    notificationCenter.attach(&mobileAPP);
    notificationCenter.attach(&auditLog);

    scheduler.summit(move(morningRoutine));
    scheduler.summit(move(harvestCommand));
    scheduler.summit(move(sensorCommand));

    cout << "\nRun All Command\n";
    scheduler.runALL();

    cout << "\nUndo\n";
    scheduler.undo();

    cout << "\nRedo\n";
    scheduler.redo();

    cout << "\nDetach MobileAPP\n";
    notificationCenter.detach(&mobileAPP);

    auto harvestCommand2 = make_unique<HarvestCommand>(&harvestSystem);
    scheduler.summit(move(harvestCommand2));
    scheduler.runALL();

    cout << "----------------------------------------------" << endl;
    cout << "q5" << endl;
    ConcreteDrinkBuilder builder;
    DrinkDirector director;

    auto blackTea = director.makeStandardBlackTea(builder);
    cout << "Standard Black Tea" << "\n";
    cout << "Description: " << blackTea->getDescrptionn() << "\n";
    cout << "Price: " << blackTea->getPrice() << "\n";
    cout << "Calories: " << blackTea->getCalories() << "\n";

    auto fruitTea = builder.setType(DrinkType::FruitTea).setSize(DrinkSize::Medium).setSugar(SugarLevel::QuarterSugar).setIce(IceLevel::LessIce).build();

    cout << "Fruit Tea preparation" << "\n";

    FruitTeaPrepartion preparation;
    preparation.prepare();

    fruitTea = make_unique<FreshFruitDecorator>(move(fruitTea));
    fruitTea = make_unique<HoneyDecorator>(move(fruitTea));
    fruitTea = make_unique<CheeseFoamDecorator>(move(fruitTea));

    cout << "Final Fruit Tea" << "\n";
    cout << "Description: " << fruitTea->getDescrptionn() << "\n";
    cout << "Price: " << fruitTea->getPrice() << "\n";
    cout << "Calories: " << fruitTea->getCalories() << "\n";

    cout << "----------------------------------------------" << endl;
    cout << "q6" << endl;
    

    return 0;
}
