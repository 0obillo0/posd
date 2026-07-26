#include<string>
#include<memory>
#include"summer_fertilizer.h"
using namespace std;


SummerFertilizer::SummerFertilizer(const string& name, double ratio,const string& descrption): _name(name), _ratio(ratio), _descrption(descrption){

}
string SummerFertilizer::getName() const{
    return _name;
}
double SummerFertilizer::getRecommendedRatio() const{
    return _ratio;
}
string SummerFertilizer::getDescription() const{
    return _descrption;
}
unique_ptr<Fertilizer> SummerFertilizer::clone() const{
    return make_unique<Fertilizer>(*this);
}