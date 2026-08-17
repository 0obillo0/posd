#include"drink_decorator.h"

DrinkDecorator::DrinkDecorator(unique_ptr<Drink> drink): _drink(move(drink)){
}

DrinkSize DrinkDecorator::getSize() const{
    return _drink->getSize();
}

SugarLevel DrinkDecorator::getScugarLevel() const{
    return _drink->getScugarLevel();
}

IceLevel DrinkDecorator::getIceLevel() const{
    return _drink->getIceLevel();
}

