#ifndef GREEN_TEA_PREPARTION_H
#define GREEN_TEA_PREPARTION_H

#include"drink_preparation.h"

class GreenTeaPrepartion : public DrinKPreparation{
protected:
    virtual void prepareBase() override;
    virtual void addMainIngredient() override;
};
#endif