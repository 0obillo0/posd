#include<string>
#include<memory>
#include"spring_pesticide.h"
using namespace std;


SpringPesticide::SpringPesticide(const string& name, double ratio,const string& descrption): _name(name), _ratio(ratio), _descrption(descrption){

}
string SpringPesticide::getName() const{
    return _name;
}
double SpringPesticide::getRecommendedRatio() const{
    return _ratio;
}
string SpringPesticide::getDescription() const{
    return _descrption;
}
unique_ptr<Pesticide> SpringPesticide::clone() const{
    return make_unique<Pesticide>(*this);
}