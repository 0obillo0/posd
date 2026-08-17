#ifndef DRINK_BUILDER_H
#define DRINK_BUILDER_H

#include<memory>
#include"drink.h"

using namespace std;

class DrinkBuilder{
public:
    virtual ~DrinkBuilder() = default;

    virtual DrinkBuilder& setType(DrinkType type) = 0;
    virtual DrinkBuilder& setSize(DrinkSize size) = 0;
    virtual DrinkBuilder& setSugar(SugarLevel sugar) = 0;
    virtual DrinkBuilder& setIce(IceLevel ice) = 0;
    virtual unique_ptr<Drink> build() = 0;

};
#endif