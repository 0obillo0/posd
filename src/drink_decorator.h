#ifndef DRINK_DECORATOR_H
#define DRINK_DECORATOR_H

#include<memory>
#include"drink.h"

class DrinkDecorator : public Drink{
protected:
    unique_ptr<Drink> _drink;
public:
    explicit DrinkDecorator(unique_ptr<Drink> drink);

    virtual ~DrinkDecorator() = default;
    void prepare();
    DrinkSize getSize() const override;
    SugarLevel getScugarLevel() const override;
    IceLevel getIceLevel() const override;
};
#endif