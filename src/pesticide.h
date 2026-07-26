#ifndef PESTICIDE_H
#define PESTICIDE_H

#include<string>
#include<memory>
using namespace std;

class Pesticide{
public:
    virtual ~Pesticide() = default;
    virtual string getName() const = 0;
    virtual double getRecommendedRatio() const = 0;
    virtual string getDescription() const = 0;
    virtual unique_ptr<Pesticide> clone() const = 0;
};

#endif


