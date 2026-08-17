#ifndef MILK_TEA_PREPARTION_H
#define MILK_TEA_PREPARTION_H

#include"drink_preparation.h"

class MilkTeaPrepartion : public DrinKPreparation{
protected:
    virtual void prepareBase() override;
    virtual void addMainIngredient() override;
};
#endif