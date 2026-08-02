#include<string>
#include<memory>
#include"summer_pesticide.h"
using namespace std;


SummerPesticide::SummerPesticide(const string& name, double ratio,const string& descrption): _name(name), _ratio(ratio), _descrption(descrption){

}
string SummerPesticide::getName() const{
    return _name;
}
double SummerPesticide::getRecommendedRatio() const{
    return _ratio;
}
string SummerPesticide::getDescription() const{
    return _descrption;
}
unique_ptr<Pesticide> SummerPesticide::clone() const{
    return make_unique<SummerPesticide>(*this);
}