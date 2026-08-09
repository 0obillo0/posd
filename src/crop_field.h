#ifndef CROP_FIELD_H
#define CROP_FIELD_H

#include<string>
#include"farm_component.h"

using namespace std;

class CropField: public FarmComponent{
private:
    string _name;
    string _cropName;
    double _area;
    double _x;
    double _y;
    string _growthStage;
    bool _sprayed = false;
public:
    CropField(
        const string& _name,
        const string& _cropName,
        double _area,
        double _x,
        double _y,
        const string& _growthStage
    );
    
    string getName() const override;
    double getArea() const override;
    void display() const override;
    void accept(vector<CropField*>& fields) override;
    unique_ptr<FieldIterator> createIterator() override;

    double getX() const;
    double getY() const;

    string getCropName() const;
    string getGrowthStage() const;

    bool isSprayed() const;
    void setSprayed(bool value);

};

#endif
