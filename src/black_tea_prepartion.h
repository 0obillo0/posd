#ifndef BLACK_TEA_PREPARTION_H
#define BLACK_TEA_PREPARTION_H

#include"drink_preparation.h"

class BlackTeaPrepartion : public DrinKPreparation{
protected:
    virtual void prepareBase() override;
    virtual void addMainIngredient() override;
};
#endif