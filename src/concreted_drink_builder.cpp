#include"concreted_drink_builder.h"
#include"base_drink.h"

#include<memory>

ConcreteDrinkBuilder::ConcreteDrinkBuilder(): _type(DrinkType::BlackTea), _size(DrinkSize::Small), _sugar(SugarLevel::RegularSugar), _ice(IceLevel::NoIce){
}

DrinkBuilder& ConcreteDrinkBuilder::setType(DrinkType type){
    this->_type = type;
    return *this;
}
DrinkBuilder& ConcreteDrinkBuilder::setSize(DrinkSize size){
    this->_size = size;
    return *this;
}
DrinkBuilder& ConcreteDrinkBuilder::setSugar(SugarLevel sugar){
    this->_sugar = sugar;
    return *this;
}
DrinkBuilder& ConcreteDrinkBuilder::setIce(IceLevel ice){
    this->_ice = ice;
    return *this;
}
unique_ptr<Drink> ConcreteDrinkBuilder::build(){
    double price = 50.0;
    int calories = 100;

    return make_unique<BaseDrink>(_type, _size, _sugar, _ice, price, calories);
}