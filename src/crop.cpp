#include"crop.h"

using namespace std;


Crop::Crop(const string& name, CropType type, double area): _name(name), _type(type), _area(area), _strategy(nullptr){
    if(area < 0.0)
        printf("area should bigger than 0.");  
}
string Crop::getName() const{
    return _name;
}
CropType Crop::getType() const{
    return _type;
}
double Crop::getArea() const{
    return _area;
}

void Crop::setSprayStrategy(unique_ptr<SprayStrategy> strategy){
    this->_strategy = move(strategy);
}

void Crop::performSpray() const{
    _strategy->spray(_name,_area);
}