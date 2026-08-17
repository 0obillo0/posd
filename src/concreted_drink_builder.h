#ifndef CONCRETED_DRINK_BUILDER_H
#define CONCRETED_DRINK_BUILDER_H

#include<memory>
#include"drink_builder.h"

using namespace std;

class ConcreteDrinkBuilder : public DrinkBuilder{
private:
    DrinkType _type;
    DrinkSize _size;
    SugarLevel _sugar;
    IceLevel _ice;
public:
    ConcreteDrinkBuilder();

    DrinkBuilder& setType(DrinkType type) override;
    DrinkBuilder& setSize(DrinkSize size) override;
    DrinkBuilder& setSugar(SugarLevel sugar) override;
    DrinkBuilder& setIce(IceLevel ice) override;
    unique_ptr<Drink> build() override;

};
#endif