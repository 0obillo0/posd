#ifndef AGRICULTURAL_MATERIAL_h
#define AGRICULTURAL_MATERIAL_h

#include<string>
using namespace std;


class AgriculturalMaterial{
public:    
    virtual ~AgriculturalMaterial() = default;
    virtual string getName() const = 0;
    virtual string getMaterialType() const = 0;
    virtual string getDescription() const = 0;
    virtual void apply(double area) const = 0;
};


#endif