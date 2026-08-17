#ifndef HONEY_DECORATOR_H
#define HONEY_DECORATOR_H

#include"drink_decorator.h"

using namespace std;

class HoneyDecorator : public DrinkDecorator{
public:
    explicit HoneyDecorator(unique_ptr<Drink> drink);

    string getDescrptionn() const override;
    double getPrice() const override;
    int getCalories() const override;
};
#endif