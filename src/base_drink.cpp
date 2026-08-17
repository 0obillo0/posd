#include"base_drink.h"

BaseDrink::BaseDrink(DrinkType type, DrinkSize size, SugarLevel sugar, IceLevel ice, double price, int calories): _type(type), _size(size), _sugar(sugar), _ice(ice), _price(price), _calories(calories)
{}

string BaseDrink::getDescrptionn() const{
    switch (_type)
    {
    case DrinkType::BlackTea:
        return "Black Tea";
    case DrinkType::GreenTea:
        return "Green Tea";
    case DrinkType::FruitTea:
        return "Fruit Tea";
    case DrinkType::MilkTea:
        return "Milk Tea";    
    }
}

double BaseDrink::getPrice() const{
    return _price;
}

int BaseDrink::getCalories() const{
    return _calories;
}
DrinkSize BaseDrink::getSize() const{
    return _size;
}

SugarLevel BaseDrink::getScugarLevel() const{
    return _sugar;
}

IceLevel BaseDrink::getIceLevel() const{
    return _ice;
}