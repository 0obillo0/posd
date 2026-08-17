#include"fresh_milk_decorator.h"

FreshMilkDecorator::FreshMilkDecorator(unique_ptr<Drink> drink):DrinkDecorator(move(drink)){
}

string FreshMilkDecorator::getDescrptionn() const{
    return _drink->getDescrptionn() + " + fresh milk";
}

double FreshMilkDecorator::getPrice() const{
    return _drink->getPrice() + 5.0;
}

int FreshMilkDecorator::getCalories() const{
    return _drink->getCalories() + 5;
}