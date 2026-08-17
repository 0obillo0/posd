#ifndef FRUIT_TEA_PREPARTION_H
#define FRUIT_TEA_PREPARTION_H

#include"drink_preparation.h"

class FruitTeaPrepartion : public DrinKPreparation{
protected:
    virtual void prepareBase() override;
    virtual void addMainIngredient() override;
    virtual void specialProcessing() override;
};
#endif