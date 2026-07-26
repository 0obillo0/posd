#ifndef CROP_H
#define CROP_H
#include<memory>
#include"spray_strategy.h"
using namespace std;


enum class CropType{
    LeafVegetable,
    Fruit,
    FruitTree,
    Tea
};

class Crop{
private:
    string _name;
    CropType _type;
    double _area;
    unique_ptr<SprayStrategy> _strategy;

public:
    ~Crop() = default;
    Crop(const string& name, CropType type, double area);
    string getName() const;
    CropType getType() const;
    double getArea() const;

    void setSprayStrategy(unique_ptr<SprayStrategy> strategy);
    void performSpray() const;
};

#endif