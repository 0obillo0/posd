#ifndef DRINK_H
#define DRINK_H

#include<string>
#include"drink_types.h"

using namespace std;

class Drink{
public:
    virtual ~Drink() = default;

    virtual string getDescrptionn() const = 0;
    virtual double getPrice() const = 0;
    virtual int getCalories() const = 0;
    virtual DrinkSize getSize() const = 0;
    virtual SugarLevel getScugarLevel() const = 0;
    virtual IceLevel getIceLevel() const = 0;
};
#endif