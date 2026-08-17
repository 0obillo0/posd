#include"drink_director.h"


unique_ptr<Drink> DrinkDirector::makeStandardBlackTea(DrinkBuilder& builder) const{
    return builder.setType(DrinkType::BlackTea).setSize(DrinkSize::Large).setSugar(SugarLevel::HalfSugar).setIce(IceLevel::LessIce).build();
}
unique_ptr<Drink> DrinkDirector::makeStandardGreanTea(DrinkBuilder& builder) const{
    return builder.setType(DrinkType::GreenTea).setSize(DrinkSize::Medium).setSugar(SugarLevel::NoSugar).setIce(IceLevel::LessIce).build();
}
unique_ptr<Drink> DrinkDirector::makeStandardFruitTea(DrinkBuilder& builder) const{
    return builder.setType(DrinkType::FruitTea).setSize(DrinkSize::Small).setSugar(SugarLevel::QuarterSugar).setIce(IceLevel::NoIce).build();
}