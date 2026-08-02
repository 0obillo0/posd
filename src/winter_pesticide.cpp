#include<string>
#include<memory>
#include"winter_pesticide.h"
using namespace std;


WinterPesticide::WinterPesticide(const string& name, double ratio,const string& descrption): _name(name), _ratio(ratio), _descrption(descrption){

}
string WinterPesticide::getName() const{
    return _name;
}
double WinterPesticide::getRecommendedRatio() const{
    return _ratio;
}
string WinterPesticide::getDescription() const{
    return _descrption;
}
unique_ptr<Pesticide> WinterPesticide::clone() const{
    return make_unique<WinterPesticide>(*this);
}