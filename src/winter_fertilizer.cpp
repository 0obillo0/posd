#include<string>
#include<memory>
#include"winter_fertilizer.h"
using namespace std;


WinterFertilizer::WinterFertilizer(const string& name, double ratio,const string& descrption): _name(name), _ratio(ratio), _descrption(descrption){

}
string WinterFertilizer::getName() const{
    return _name;
}
double WinterFertilizer::getRecommendedRatio() const{
    return _ratio;
}
string WinterFertilizer::getDescription() const{
    return _descrption;
}
unique_ptr<Fertilizer> WinterFertilizer::clone() const{
    return make_unique<Fertilizer>(*this);
}