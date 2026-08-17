#include"goat_milk_decorator.h"

GoatMilkDecorator::GoatMilkDecorator(unique_ptr<Drink> drink):DrinkDecorator(move(drink)){
}

string GoatMilkDecorator::getDescrptionn() const{
    return _drink->getDescrptionn() + " + goat milk";
}

double GoatMilkDecorator::getPrice() const{
    return _drink->getPrice() + 20.0;
}

int GoatMilkDecorator::getCalories() const{
    return _drink->getCalories() + 20;
}