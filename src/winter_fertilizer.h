#ifndef WINTER_FERTILIZER_H
#define WINTER_FERTILIZER_H

#include<string>
#include<memory>
#include"fertilizer.h"
using namespace std;

class WinterFertilizer : public Fertilizer{
private:
    string _name;
    double _ratio;
    string _descrption; 
public:
    WinterFertilizer(const string& name = "winter", double ratio = 0.0,const string& descrption = "");
    string getName() const override;
    double getRecommendedRatio() const override;
    string getDescription() const override;
    unique_ptr<Fertilizer> clone() const override;
};

#endif

