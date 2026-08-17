#ifndef GOAT_MILK_DECORATOR_H
#define GOAT_MILK_DECORATOR_H

#include"drink_decorator.h"

using namespace std;

class GoatMilkDecorator : public DrinkDecorator{
public:
    explicit GoatMilkDecorator(unique_ptr<Drink> drink);

    string getDescrptionn() const override;
    double getPrice() const override;
    int getCalories() const override;
};
#endif