#include"leaf_vegetable_fertilizer.h"

string LeafVegetableFertilizer::getName() const{
    return "LeafVegetableFertilizer Name";
} 
string LeafVegetableFertilizer::getMaterialType() const{
    return "LeafVegetableFertilizer MaterialType";
}
string LeafVegetableFertilizer::getDescription() const{
    return "LeafVegetableFertilizer Description";
}
void LeafVegetableFertilizer::apply(double area) const{
    printf("%lf\n", area);
}