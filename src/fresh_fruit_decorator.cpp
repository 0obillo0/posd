#include"fresh_fruit_decorator.h"

FreshFruitDecorator::FreshFruitDecorator(unique_ptr<Drink> drink):DrinkDecorator(move(drink)){
}

string FreshFruitDecorator::getDescrptionn() const{
    return _drink->getDescrptionn() + " + fresh fruit";
}

double FreshFruitDecorator::getPrice() const{
    return _drink->getPrice() + 15.0;
}

int FreshFruitDecorator::getCalories() const{
    return _drink->getCalories() + 15;
}