#ifndef WINTER_PESTICIDE_H
#define WINTER_PESTICIDE_H

#include<string>
#include<memory>
#include"pesticide.h"
using namespace std;

class WinterPesticide : public Pesticide{
private:
    string _name;
    double _ratio;
    string _descrption;
public:
    WinterPesticide(const string& name = "winter", double ratio = 0.0,const string& descrption = "");
    string getName() const override;
    double getRecommendedRatio() const override;
    string getDescription() const override;
    unique_ptr<Pesticide> clone() const override;
};

#endif

