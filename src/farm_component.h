#ifndef FARM_COMPONENT_H
#define FARM_COMPONENT_H

#include<string>
#include<memory>
#include<vector>

using namespace std;

class FieldIterator;
class CropField;
class FarmComponent{
public:
    virtual ~FarmComponent() = default;
    virtual string getName() const = 0;
    virtual double getArea() const = 0;
    virtual void display() const = 0;
    virtual void accept(vector<CropField*>& fields) = 0;
    virtual unique_ptr<FieldIterator> createIterator() = 0;

};
#endif