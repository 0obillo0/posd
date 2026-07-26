#include"biological_control_agent.h"

string BiologicalControlAgent::getName() const{
    return "BiologicalControlAgent Name";
} 
string BiologicalControlAgent::getMaterialType() const{
    return "BiologicalControlAgent MaterialType";
}
string BiologicalControlAgent::getDescription() const{
    return "BiologicalControlAgent Description";
}
void BiologicalControlAgent::apply(double area) const{
    printf("%lf\n", area);
}