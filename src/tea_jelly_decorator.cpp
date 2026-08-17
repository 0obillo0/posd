#include"tea_jelly_decorator.h"

TeaJellyDecorator::TeaJellyDecorator(unique_ptr<Drink> drink):DrinkDecorator(move(drink)){
}

string TeaJellyDecorator::getDescrptionn() const{
    return _drink->getDescrptionn() + " + tea jelly";
}

double TeaJellyDecorator::getPrice() const{
    return _drink->getPrice() + 30.0;
}

int TeaJellyDecorator::getCalories() const{
    return _drink->getCalories() + 30;
}