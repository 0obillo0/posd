#include<iostream>

#include"crop_field.h"
#include"farm_iterator.h"

CropField::CropField(
    const string& name,
    const string& cropName,
    double area,
    double x,
    double y,
    const string& growthStage
):_name(name), _cropName(cropName), _area(area), _x(x), _y(y), _growthStage(growthStage){
}

string CropField::getName() const{
    return _name;
}
double CropField::getArea() const{
    return _area;
}
void CropField::display() const{
    cout << _name << "\n";
    cout << "Crop: "<< _cropName << "\n";
    cout << "Area: "<< _area << "\n";
    cout << "Stage: "<< _growthStage << "\n";
    cout << "Sprayed: "<< (_sprayed ? "YES" : "NO") << "\n";
}
void CropField::accept(vector<CropField*>& fields){
    fields.push_back(this);
}

unique_ptr<FieldIterator> CropField::createIterator(){
    return make_unique<FarmIterator>(this);
}

double CropField::getX() const{
    return _x;
}
double CropField::getY() const{
    return _y;
}

string CropField::getCropName() const{
    return _cropName;
}
string CropField::getGrowthStage() const{
    return _growthStage;
}

bool CropField::isSprayed() const{
    return _sprayed;
}
void CropField::setSprayed(bool value){
    _sprayed = value;
}
