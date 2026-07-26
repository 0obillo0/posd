#include"fruit_pesticide.h"

string FruitPesticide::getName() const{
    return "FruitPesticide Name";
} 
string FruitPesticide::getMaterialType() const{
    return "FruitPesticide MaterialType";
}
string FruitPesticide::getDescription() const{
    return "FruitPesticide Description";
}
void FruitPesticide::apply(double area) const{
    printf("%lf\n", area);
}