
#ifndef FARM_AREA_H
#define FARM_AREA_H

#include<string>
#include<memory>
#include<vector>
#include"farm_component.h"
#include"crop_field.h"
using namespace std;



class FarmArea: public FarmComponent{
private:
    string _name;
    vector<unique_ptr<FarmComponent>> _children;
public:
    explicit FarmArea(const string& name);
    void add(unique_ptr<FarmComponent> compoent);
    void remove(const string& name);

    FarmComponent* getChild(int index);

    string getName() const override;
    double getArea() const override;
    void display() const override;
    void accept(vector<CropField*>& fields) override;
    unique_ptr<FieldIterator> createIterator() override;

};
#endif