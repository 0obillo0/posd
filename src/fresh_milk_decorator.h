#ifndef FRESH_MILK_DECORATOR_H
#define FRESH_MILK_DECORATOR_H

#include"drink_decorator.h"

using namespace std;

class FreshMilkDecorator : public DrinkDecorator{
public:
    explicit FreshMilkDecorator(unique_ptr<Drink> drink);

    string getDescrptionn() const override;
    double getPrice() const override;
    int getCalories() const override;
};
#endif