#ifndef CHEESE_FOAM_DECORATOR_H
#define CHEESE_FOAM_DECORATOR_H

#include"drink_decorator.h"

using namespace std;

class CheeseFoamDecorator : public DrinkDecorator{
public:
    explicit CheeseFoamDecorator(unique_ptr<Drink> drink);

    string getDescrptionn() const override;
    double getPrice() const override;
    int getCalories() const override;
};
#endif