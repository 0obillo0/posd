#include<string>
#include<memory>
#include"spring_fertilizer.h"
using namespace std;


SpringFertilizer::SpringFertilizer(const string& name, double ratio,const string& descrption): _name(name), _ratio(ratio), _descrption(descrption){
}
string SpringFertilizer::getName() const{
    return _name;
}
double SpringFertilizer::getRecommendedRatio() const{
    return _ratio;
}
string SpringFertilizer::getDescription() const{
    return _descrption;
}
unique_ptr<Fertilizer> SpringFertilizer::clone() const{
    return make_unique<SpringFertilizer>(*this);
}