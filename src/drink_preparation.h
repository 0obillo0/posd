#ifndef DRINK_PREPARATION_H
#define DRINK_PREPARATION_H

using namespace std;

class DrinKPreparation{
public:
    virtual ~DrinKPreparation() = default;
    void prepare();

protected:
    virtual void prepareCup();
    virtual void prepareBase() = 0;
    virtual void addMainIngredient() = 0;
    virtual void specialProcessing();
    virtual void adjustSugarAndIce();
    virtual void finish();
};
#endif