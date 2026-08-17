#ifndef FRESH_FRUIT_DECORATOR_H
#define FRESH_FRUIT_DECORATOR_H

#include"drink_decorator.h"

using namespace std;

class FreshFruitDecorator : public DrinkDecorator{
public:
    explicit FreshFruitDecorator(unique_ptr<Drink> drink);

    string getDescrptionn() const override;
    double getPrice() const override;
    int getCalories() const override;
};
#endif