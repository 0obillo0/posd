#ifndef SPRING_PESTICIDE_H
#define SPRING_PESTICIDE_H

#include<string>
#include<memory>
#include"pesticide.h"
using namespace std;

class SpringPesticide : public Pesticide{
private:
    string _name;
    double _ratio;
    string _descrption;
public:
    SpringPesticide(const string& name, double ratio,const string& descrption);
    string getName() const override;
    double getRecommendedRatio() const override;
    string getDescription() const override;
    unique_ptr<Pesticide> clone() const override;
};

#endif

