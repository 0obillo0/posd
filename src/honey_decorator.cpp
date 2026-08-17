#include"honey_decorator.h"

HoneyDecorator::HoneyDecorator(unique_ptr<Drink> drink):DrinkDecorator(move(drink)){
}

string HoneyDecorator::getDescrptionn() const{
    return _drink->getDescrptionn() + " + honey";
}

double HoneyDecorator::getPrice() const{
    return _drink->getPrice() + 25.0;
}

int HoneyDecorator::getCalories() const{
    return _drink->getCalories() + 25;
}