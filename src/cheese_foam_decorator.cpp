#include"cheese_foam_decorator.h"

CheeseFoamDecorator::CheeseFoamDecorator(unique_ptr<Drink> drink):DrinkDecorator(move(drink)){
}

string CheeseFoamDecorator::getDescrptionn() const{
    return _drink->getDescrptionn() + " + cheese foam";
}

double CheeseFoamDecorator::getPrice() const{
    return _drink->getPrice() + 10.0;
}

int CheeseFoamDecorator::getCalories() const{
    return _drink->getCalories() + 10;
}