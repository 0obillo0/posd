#ifndef DRINK_DIRECTOR_H
#define DRINK_DIRECTOR_H

#include<memory>
#include"drink_builder.h"

using namespace std;

class DrinkDirector{
public:
    unique_ptr<Drink> makeStandardBlackTea(DrinkBuilder& builder) const;
    unique_ptr<Drink> makeStandardGreanTea(DrinkBuilder& builder) const;
    unique_ptr<Drink> makeStandardFruitTea(DrinkBuilder& builder) const;
};
#endif