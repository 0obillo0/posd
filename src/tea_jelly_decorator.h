#ifndef TEA_JELLY_DECORATOR_H
#define TEA_JELLY_DECORATOR_H

#include"drink_decorator.h"

using namespace std;

class TeaJellyDecorator : public DrinkDecorator{
public:
    explicit TeaJellyDecorator(unique_ptr<Drink> drink);

    string getDescrptionn() const override;
    double getPrice() const override;
    int getCalories() const override;
};
#endif