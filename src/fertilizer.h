#ifndef FERTILIZER_H
#define FERTILIZER_H

#include<string>
#include<memory>
using namespace std;

class Fertilizer{
public:
    virtual ~Fertilizer() = default;
    virtual string getName() const = 0;
    virtual double getRecommendedRatio() const = 0;
    virtual string getDescription() const = 0;
    virtual unique_ptr<Fertilizer> clone() const = 0;
};

#endif


