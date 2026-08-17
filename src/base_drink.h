#ifndef BASE_DRINK_H
#define BASE_DRINK_H

#include<string>
#include"drink.h"

using namespace std;

class BaseDrink : public Drink{
private:
    DrinkType _type;
    DrinkSize _size;
    SugarLevel _sugar;
    IceLevel _ice;
    double _price;
    int _calories;

public:
    BaseDrink(DrinkType type, DrinkSize size, SugarLevel sugar, IceLevel ice, double price, int calories);
    string getDescrptionn() const override;
    double getPrice() const override;
    int getCalories() const override;
    DrinkSize getSize() const override;
    SugarLevel getScugarLevel() const override;
    IceLevel getIceLevel() const override;
};
#endif